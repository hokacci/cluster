#include <iostream>
#include <memory>

#include <matplot/matplot.h>

#include "blobs_2d.h"
#include "kmeans.h"
#include "point_2d.h"

int main()
{
	std::vector<double> sses(10);
	std::vector<double> ks(10);
	for (int k = 1; k <= 10; ++k)
	{
		auto kmeans = yhok::cluster::kmeans_plus_plus_multi(5, k, 100, dataset_blobs_2d);
		sses[k - 1] = kmeans->sse;
		ks[k - 1] = k;
	}
	auto p = matplot::plot(sses);
	p->line_width(5);
	p->marker_style(matplot::line_spec::marker_style::circle);
	p->marker_size(10);
	p->marker_face(true);
	matplot::title("Elbow Method");
	matplot::show();

	return 0;
}