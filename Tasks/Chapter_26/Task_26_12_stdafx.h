#ifndef TASK_26_12_STDAFX_H
#define TASK_26_12_STDAFX_H

#include <iostream>
#include <chrono>
#include <algorithm>
#include <limits>
#include <vector>

#endif

inline double rand_double(double min, double max)
{
	double value = double(rand()) / RAND_MAX;
	return min + value * (max - min);
}

void vector_generate_and_sort(
	const size_t size, 
	double min = std::numeric_limits<double>::min(), 
	double max = std::numeric_limits<double>::max())
{
	auto timeStart = std::chrono::system_clock::now();
	
	std::cout << "Arr, size = " << size << '\n';
	srand(static_cast<unsigned int>(time(NULL)));
	std::vector<double> arr;
	arr.reserve(size);
	for (auto i = 0; i < size; ++i)
	{
		arr.push_back(rand_double(min, max));
	}
	std::sort(arr.begin(), arr.end());

	auto timeFinish = std::chrono::system_clock::now();
	std::cout << "Time for operation is\t" <<
		std::chrono::duration_cast<std::chrono::milliseconds>(timeFinish - timeStart).count() << "ms";
	std::cout << "\n";
}