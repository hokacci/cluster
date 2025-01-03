#include <iostream>

#include <matplot/matplot.h>

#include "blobs_2d.h"
#include "kmeans.h"
#include "point_2d.h"

int main()
{
	yhok::cluster::KMeans kmeans(3, 100, dataset_blobs_2d);

	kmeans.exec();

	std::vector<double> x(kmeans.m);
	std::vector<double> y(kmeans.m);
	std::vector<double> c(kmeans.m);
	for (int i = 0; i < kmeans.m; ++i)
	{
		x[i] = kmeans.points[i].x;
		y[i] = kmeans.points[i].y;
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

	matplot::show();

	return 0;
}