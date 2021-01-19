#ifndef TASK_26_13_STDAFX_H
#define TASK_26_13_STDAFX_H

#include <iostream>
#include <chrono>
#include <algorithm>
#include <limits>
#include <vector>

#endif

inline int rand_int(int max)
{
	return rand() % max;
}

std::string rand_string()
{
	int length = rand_int(100);
	std::string string;
	for (int i = 0; i < length; ++i)
	{
		string += char(rand_int(std::numeric_limits<char>::max()));
	}
	return string;
}

void vector_generate_and_sort(
	const size_t size, 
	double min = std::numeric_limits<double>::min(), 
	double max = std::numeric_limits<double>::max())
{
	auto timeStart = std::chrono::system_clock::now();
	
	std::cout << "Arr, size = " << size << '\n';
	srand(static_cast<unsigned int>(time(NULL)));
	std::vector<std::string> arr;
	arr.reserve(size);
	for (auto i = 0; i < size; ++i)
	{
		arr.push_back(rand_string());
	}
	std::sort(arr.begin(), arr.end());

	auto timeFinish = std::chrono::system_clock::now();
 	std::cout << "Time for operation is\t" <<
		std::chrono::duration_cast<std::chrono::milliseconds>(timeFinish - timeStart).count() << "ms";
	std::cout << "\n";
}