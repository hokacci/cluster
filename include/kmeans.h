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

	// K-means法を実行
	template <KMeansablePoint Point>
	void exec_kmeans(
		std::vector<Point> &points, int k, int max_iter, std::vector<int> &labels_out, std::vector<Point> &centroids_out
	)
	{
		// セントロイドを初期化
		// ランダムにk個の点を選ぶ
		std::random_device seed_gen;
		std::mt19937 engine(seed_gen());
		std::uniform_int_distribution<> dist(0, points.size() - 1);

		centroids_out.resize(k);
		for (auto &&centroid : centroids_out)
		{
			centroid = points[dist(engine)];
		}

		// データの点数
		int m = points.size();

		// 各点がどのクラスタに属するかを保持する配列
		labels_out.resize(m);

		// K-means法の繰り返し
		for (int iter = 0; iter < max_iter; ++iter)
		{

			// ステップ1: 各点を最も近いセントロイドに割り当てる
			for (int i = 0; i < m; ++i)
			{
				double min_dist = std::numeric_limits<double>::max();
				for (int j = 0; j < k; ++j)
				{
					double dist = distance(points[i], centroids_out[j]);
					if (dist < min_dist)
					{
						min_dist = dist;
						labels_out[i] = j;
					}
				}
			}

			// ステップ2: 各クラスタの重心を計算して、セントロイドを更新する
			std::vector<std::vector<Point>> points_in_cluster(k);

			for (int i = 0; i < m; ++i)
			{
				int cluster = labels_out[i];
				points_in_cluster[cluster].push_back(points[i]);
			}
			for (int i = 0; i < k; ++i)
			{
				centroids_out[i] = center(points_in_cluster[i]);
			}
		}
	}

} // namespace yhok