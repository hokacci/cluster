#pragma once

#include <concepts>
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

		KMeans(int k, int max_iter, const std::vector<Point> &points)
			: k(k), max_iter(max_iter), points(points), m(points.size()), labels(m), centroids(k)
		{
		}

		// K-means法を実行する
		void exec()
		{
			init_centroids();
			update_labels();

			for (int i = 0; i < max_iter; ++i)
			{
				update_centroids();
				bool updated = update_labels();
				if (!updated)
				{
					break;
				}
			}
		}

		// セントロイドを初期化
		// pointsからランダムにk個の点を選ぶ
		void init_centroids()
		{
			std::random_device seed_gen;
			std::mt19937 engine(seed_gen());
			std::uniform_int_distribution<> dist(0, m - 1);

			for (auto &&centroid : centroids)
			{
				centroid = points[dist(engine)];
			}
		}

		// 各点を最も近いセントロイドに割り当てる
		// 割り当てが変わった場合はtrueを返す
		bool update_labels()
		{
			bool updated = false;
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

} // namespace yhok::cluster