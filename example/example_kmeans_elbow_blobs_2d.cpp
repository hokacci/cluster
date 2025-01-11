#include <iostream>
#include <memory>

#include <matplot/matplot.h>

#include "blobs_2d.h"
#include "kmeans.h"
#include "point_2d.h"

// k-means++をn回実行し、SSEが最良のものを返す
static std::unique_ptr<yhok::cluster::KMeans<Point2D>> kmeans_plus_plus_multi(
	int n, int k, int max_iter, const std::vector<Point2D> &points
)
{
	// 最良のk-means法の結果を格納する
	auto kmeans_opt = std::make_unique<yhok::cluster::KMeans<Point2D>>(k, max_iter, points);
	kmeans_opt->sse = std::numeric_limits<double>::max();

	// k-means法を実行する
	auto kmeans_exc = std::make_unique<yhok::cluster::KMeans<Point2D>>(k, max_iter, points);

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

int main()
{
	std::vector<double> sses(10);
	std::vector<double> ks(10);
	for (int k = 1; k <= 10; ++k)
	{
		auto kmeans = kmeans_plus_plus_multi(5, k, 100, dataset_blobs_2d);
		sses[k - 1] = kmeans->sse;
		ks[k - 1] = k;
	}
	matplot::plot(sses);
	matplot::title("Elbow Method");
	matplot::show();

	return 0;
}