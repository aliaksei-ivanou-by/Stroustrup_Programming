#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include "Task_25_Pool.h"
#include "Task_25_Stack.h"

inline int randint(int max)
{
	return rand() % max;
}

inline int randint(int min, int max)
{
	return randint(max - min) + min;
}

struct chars
{
	char arr[500];
};

struct Timer
{
	std::chrono::system_clock::time_point time;
	Timer() :
		time{ std::chrono::system_clock::now() }
	{}
	void reset()
	{
		time = std::chrono::system_clock::now();
	}
	void operator()(const std::string& label)
	{
		auto time2 = std::chrono::system_clock::now();
		std::cout << label << "\t\t" <<
			std::chrono::duration_cast<std::chrono::milliseconds>(time2 - time).count() << "ms\n";
	}
};

int main()
try
{
	constexpr int size = 10'000;
	constexpr int times = 3;
	Timer timer;

	std::cout << "Part 1 - std::vector\n";
	std::cout << "Deallocate with delete in reverse order\n";
	timer.reset();
	std::vector<char*> arr1(size);
	for (int k = 0; k < times; ++k)
	{
		std::cout << "Iteration " << k << '\n';
		for (int i = 0; i < size; ++i)
		{
			arr1[i] = new char[randint(1'000) + 1];
		}
		timer("\tStep 1 _ Get array");

		timer.reset();
		for (int i = size - 1; i >= 0; --i)
		{
			delete[] arr1[i];
		}
		timer("\tStep 1 _ Delete array");
	}
	std::cout << "Deallocate with delete in random order\n";
	timer.reset();
	for (int k = 0; k < times; ++k)
	{
		std::cout << "Iteration " << k + 1 << '\n';
		for (int i = 0; i < size; ++i)
		{
			arr1[i] = new char[randint(1'000) + 1];
		}
		timer("\tStep 1 _ Get array");

		timer.reset();
		std::random_shuffle(arr1.begin(), arr1.end());
		for (int i = size - 1; i >= 0; --i)
		{
			delete[] arr1[i];
		}
		timer("\tStep 1 _ Delete array");
	}

	std::cout << "Part 2 - Pool\n";
	std::cout << "Deallocate from Pool\n";
	timer.reset();
	Pool<chars, size> pool;
	chars* arr2[size];
	for (int i = 0; i < size; ++i)
	{
		arr2[i] = pool.get_value();
	}
	timer("\tStep 1 _ Get array");

	timer.reset();
	for (int i = size - 1; i >= 0; --i)
	{
		pool.free(arr2[i]);
	}
	timer("\tStep 1 _ Delete array");

	std::cout << "Part 3 - Stack\n";
	std::cout << "Deallocate from Stack\n";
	timer.reset();
	Stack<char*> arr3(size);
	for (int i = 0; i < size; ++i)
	{
		arr3.push(new char[randint(1'000) + 1]);
	}
	timer("\tStep 1 _ Get array");

	timer.reset();
	for (int i = size - 1; i >= 0; --i)
	{
		delete[] arr3.pop();
	}
	timer("\tStep 1 _ Delete array");
}
catch (const std::exception& e)
{
	std::cout << "Exception occured: " << e.what() << '\n';
	return 1;
}
catch (...)
{
	return 2;
}
