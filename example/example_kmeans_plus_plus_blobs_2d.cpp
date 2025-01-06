#include <iostream>

#include "blobs_2d.h"
#include "kmeans.h"
#include "point_2d.h"

int main()
{
	yhok::cluster::KMeans kmeans(3, 100, dataset_blobs_2d);

	// k-meansを10000回実行して、失敗する回数を数える
	int count_failure = 0;
	for (int i = 0; i < 10000; ++i)
	{
		kmeans.exec();

		if (kmeans.labels[243] == kmeans.labels[21])
		{
			++count_failure;
		}
	}
	std::cout << "Failure rate (k-means): " << count_failure / 10000.0 << std::endl;

	// k-means++を10000回実行して、失敗する回数を数える
	count_failure = 0;
	for (int i = 0; i < 10000; ++i)
	{
		kmeans.exec_kmeans_plus_plus();

		if (kmeans.labels[243] == kmeans.labels[21])
		{
			++count_failure;
		}
	}
	std::cout << "Failure rate (k-means++): " << count_failure / 10000.0 << std::endl;

	return 0;
}