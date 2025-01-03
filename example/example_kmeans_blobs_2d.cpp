#include <iostream>

#include "blobs_2d.h"
#include "kmeans.h"
#include "point_2d.h"

int main()
{
	std::vector<Point2D> points = dataset_blobs_2d;

	std::vector<int> labels;
	std::vector<Point2D> centroids;
	yhok::cluster::exec_kmeans(points, 3, 100, labels, centroids);

	for (int i = 0; i < points.size(); ++i)
	{
		std::cout << labels[i] << "," << std::endl;
	}

	return 0;
}