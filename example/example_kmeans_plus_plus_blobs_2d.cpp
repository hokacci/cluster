#include <iostream>

#include "blobs_2d.h"
#include "kmeans.h"
#include "point_2d.h"

int main()
{
	yhok::cluster::KMeans kmeans(3, 100, dataset_blobs_2d);
	int n = 100000;

	// k-meansをn回実行して、失敗する回数を数える
	int count_failure = 0;
	int sum_iterations = 0;
	for (int i = 0; i < n; ++i)
	{
		int iterations = kmeans.exec();
		sum_iterations += iterations;

		if (kmeans.labels[243] == kmeans.labels[21])
		{
			++count_failure;
		}
	}
	std::cout << "Failure rate (k-means): " << count_failure / static_cast<double>(n) << std::endl;
	std::cout << "Average number of iterations: " << sum_iterations / static_cast<double>(n) << std::endl;

	// k-means++をn回実行して、失敗する回数を数える
	count_failure = 0;
	sum_iterations = 0;
	for (int i = 0; i < n; ++i)
	{
		int iterations = kmeans.exec_kmeans_plus_plus();
		sum_iterations += iterations;

		if (kmeans.labels[243] == kmeans.labels[21])
		{
			++count_failure;
		}
	}
	std::cout << "Failure rate (k-means++): " << count_failure / static_cast<double>(n) << std::endl;
	std::cout << "Average number of iterations: " << sum_iterations / static_cast<double>(n) << std::endl;

	return 0;
}