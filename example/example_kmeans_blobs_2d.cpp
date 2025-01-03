#include <iostream>

#include <matplot/matplot.h>

#include "blobs_2d.h"
#include "kmeans.h"
#include "point_2d.h"

int main()
{
	std::vector<Point2D> points = dataset_blobs_2d;

	std::vector<int> labels;
	std::vector<Point2D> centroids;
	yhok::cluster::exec_kmeans(points, 3, 100, labels, centroids);

	std::vector<double> x(points.size());
	std::vector<double> y(points.size());
	std::vector<double> c(points.size());
	for (int i = 0; i < points.size(); ++i)
	{
		x[i] = points[i].x;
		y[i] = points[i].y;
		c[i] = static_cast<double>(labels[i]);
	}

	auto l = matplot::scatter(x, y, std::vector<double>{}, c);
	l->marker_face(true);
	l->marker_size(8);
	matplot::hold(matplot::on);

	std::vector<double> cx(centroids.size());
	std::vector<double> cy(centroids.size());
	for (int i = 0; i < centroids.size(); ++i)
	{
		cx[i] = centroids[i].x;
		cy[i] = centroids[i].y;
	}

	auto cl = matplot::scatter(cx, cy, 30);
	cl->marker_style(matplot::line_spec::marker_style::cross);

	matplot::show();

	return 0;
}