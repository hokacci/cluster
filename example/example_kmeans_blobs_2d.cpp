#include <iostream>

#include <matplot/matplot.h>

#include "blobs_2d.h"
#include "kmeans.h"
#include "point_2d.h"

int main()
{
	yhok::cluster::KMeans kmeans(3, 100, dataset_blobs_2d);

	std::vector<double> x(kmeans.m);
	std::vector<double> y(kmeans.m);
	for (int i = 0; i < kmeans.m; ++i)
	{
		x[i] = kmeans.points[i].x;
		y[i] = kmeans.points[i].y;
	}

	// 描画関数
	auto draw = [&](int iter, int step) {
		std::vector<double> c(kmeans.m);
		for (int i = 0; i < kmeans.m; ++i)
		{
			c[i] = static_cast<double>(kmeans.labels[i]);
		}

		auto l = matplot::scatter(x, y, std::vector<double>{}, c);
		l->marker_face(true);
		l->marker_size(8);
		matplot::hold(matplot::on);

		std::vector<double> cx(kmeans.k);
		std::vector<double> cy(kmeans.k);
		for (int i = 0; i < kmeans.k; ++i)
		{
			cx[i] = kmeans.centroids[i].x;
			cy[i] = kmeans.centroids[i].y;
		}

		auto cl = matplot::scatter(cx, cy, 30);
		cl->marker_style(matplot::line_spec::marker_style::cross);

		std::string title = "iter_" + std::to_string(iter) + "_" + std::to_string(step) + ".png";
		matplot::save(title);
		matplot::cla();
	};

	// K-means法を実行し、ステップごとに描画
	kmeans.init_centroids();
	kmeans.update_labels();
	for (int iter = 0; iter < kmeans.max_iter; ++iter)
	{
		draw(iter, 0);

		kmeans.update_centroids();

		draw(iter, 1);

		bool updated = kmeans.update_labels();
		if (!updated)
		{
			break;
		}
	}

	return 0;
}