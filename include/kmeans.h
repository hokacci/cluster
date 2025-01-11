#pragma once

#include <algorithm>
#include <concepts>
#include <memory>
#include <random>
#include <vector>

namespace yhok::cluster
{

	// K-meansを実行できる点の概念
	template <typename Point>
	concept KMeansablePoint = requires(Point a, Point b, std::vector<Point> points) {
		// 2点間の距離を計算する関数が定義されていること
		{ distance(a, b) } -> std::convertible_to<double>;

		// 重心を計算する関数が定義されていること
		{ center(points) } -> std::convertible_to<Point>;
	};

	// K-means法を実行するクラス
	template <KMeansablePoint Point>
	struct KMeans
	{
		int k;
		int max_iter;
		int m;
		std::vector<Point> points;
		std::vector<int> labels;
		std::vector<Point> centroids;

		// sum of squared estimate of errors
		double sse = 0;

		KMeans(int k, int max_iter, const std::vector<Point> &points)
			: k(k), max_iter(max_iter), points(points), m(points.size()), labels(m), centroids(k)
		{
		}

		// K-means法を実行する
		// 返り値はイテレーション回数
		int exec()
		{
			init_centroids();
			update_labels();

			int i = 0;
			for (; i < max_iter; ++i)
			{
				update_centroids();
				bool updated = update_labels();
				if (!updated)
				{
					break;
				}
			}
			return i;
		}

		// k-means++を実行する
		// 返り値はイテレーション回数
		int exec_kmeans_plus_plus()
		{
			init_centroids_kmeans_plus_plus();
			update_labels();

			int i = 0;
			for (; i < max_iter; ++i)
			{
				update_centroids();
				bool updated = update_labels();
				if (!updated)
				{
					break;
				}
			}
			return i;
		}

		// セントロイドを初期化
		// pointsからランダムにk個の点を選ぶ
		void init_centroids()
		{
			std::random_device seed_gen;
			std::mt19937 engine(seed_gen());
			std::uniform_int_distribution<> distribution(0, m - 1);

			std::vector<int> used_indices;
			for (auto &&centroid : centroids)
			{
				// 重複しないようにindexを選ぶ
				int index;
				do
				{
					index = distribution(engine);
				} while (std::find(used_indices.begin(), used_indices.end(), index) != used_indices.end());

				centroid = points[index];
				used_indices.push_back(index);
			}
		}

		// K-means++法を用いてセントロイドを初期化
		void init_centroids_kmeans_plus_plus()
		{
			std::random_device seed_gen;
			std::mt19937 engine(seed_gen());
			std::uniform_int_distribution<> uniform_distribution(0, m - 1);

			// 最初のセントロイドはランダムに選ぶ
			int index = uniform_distribution(engine);
			centroids[0] = points[index];

			// 残りのセントロイドは、それまでのセントロイドとの距離が遠い点が選ばれやすいような確率分布を使って選ぶ
			// この場合、重複を考慮する必要はない (すでに選ばれたセントロイドは選ばれる確率が0となるため)
			for (int i = 1; i < k; ++i)
			{
				std::vector<double> dist2s(m);
				for (int j = 0; j < m; ++j)
				{
					double min_dist = std::numeric_limits<double>::max();
					for (int l = 0; l < i; ++l)
					{
						min_dist = std::min(min_dist, distance(points[j], centroids[l]));
					}
					dist2s[j] = min_dist * min_dist;
				}
				std::discrete_distribution<> distance_based_distribution(dist2s.begin(), dist2s.end());

				index = distance_based_distribution(engine);
				centroids[i] = points[index];
			}
		}

		// 各点を最も近いセントロイドに割り当てる
		// SSEを更新する
		// 割り当てが変わった場合はtrueを返す
		bool update_labels()
		{
			bool updated = false;
			sse = 0;
			for (int i = 0; i < m; ++i)
			{
				double min_dist = std::numeric_limits<double>::max();
				int min_label = -1;
				for (int j = 0; j < k; ++j)
				{
					double dist = distance(points[i], centroids[j]);
					if (dist < min_dist)
					{
						min_dist = dist;
						min_label = j;
					}
				}
				if (labels[i] != min_label)
				{
					updated = true;
					labels[i] = min_label;
				}
				sse += min_dist * min_dist;
			}
			return updated;
		}

		// 各クラスタの重心を計算して、セントロイドを更新する
		void update_centroids()
		{
			std::vector<std::vector<Point>> points_in_cluster(k);

			for (int i = 0; i < m; ++i)
			{
				int cluster = labels[i];
				points_in_cluster[cluster].push_back(points[i]);
			}
			for (int i = 0; i < k; ++i)
			{
				centroids[i] = center(points_in_cluster[i]);
			}
		}
	};

	// k-means++をn回実行し、SSEが最良のものを返す
	template <KMeansablePoint Point>
	std::unique_ptr<KMeans<Point>> kmeans_plus_plus_multi(int n, int k, int max_iter, const std::vector<Point> &points)
	{
		// 最良のk-means法の結果を格納する変数
		auto kmeans_opt = std::make_unique<KMeans<Point>>(k, max_iter, points);
		kmeans_opt->sse = std::numeric_limits<double>::max();

		// k-means法を実行する変数
		auto kmeans_exc = std::make_unique<KMeans<Point>>(k, max_iter, points);

		for (int i = 0; i < n; ++i)
		{
			kmeans_exc->exec_kmeans_plus_plus();
			if (kmeans_exc->sse < kmeans_opt->sse)
			{
				kmeans_opt.swap(kmeans_exc);
			}
		}

		return kmeans_opt;
	}

} // namespace yhok::cluster