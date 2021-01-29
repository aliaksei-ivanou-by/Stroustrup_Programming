#include <iostream>
#include <chrono>
#include <algorithm>
#include <limits>
#include <vector>
#include <set>

inline int rand_int(const int& max)
{
	return rand() % max;
}

inline double rand_double(double min, double max)
{
	double value = double(rand()) / RAND_MAX;
	return min + value * (max - min);
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

void vector_generate_and_sort_doubles(
	const size_t& size,
	const double& min = std::numeric_limits<double>::min(),
	const double& max = std::numeric_limits<double>::max())
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

void vector_generate_and_sort_strings(const size_t& size)
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

void set_generate_and_sort_strings(const size_t size)
{
	auto timeStart = std::chrono::system_clock::now();

	std::cout << "Arr, size = " << size << '\n';
	srand(static_cast<unsigned int>(time(NULL)));
	std::set<std::string> arr;
	for (auto i = 0; i < size; ++i)
	{
		arr.insert(rand_string());
	}

	auto timeFinish = std::chrono::system_clock::now();
	std::cout << "Time for operation is\t" <<
		std::chrono::duration_cast<std::chrono::milliseconds>(timeFinish - timeStart).count() << "ms";
	std::cout << "\n";
}

int main()
try
{
	{ // 1
		std::cout << "Generate doubles (vector)\n";
		constexpr size_t size1 = 500'000;
		constexpr size_t size2 = 5'000'000;

		vector_generate_and_sort_doubles(size1);
		vector_generate_and_sort_doubles(size2);
	}
	std::cout << '\n';
	{ // 2
		std::cout << "Generate strings (vector)\n";
		constexpr size_t size1 = 500'000;
		constexpr size_t size2 = 5'000'000;

		vector_generate_and_sort_strings(size1);
		vector_generate_and_sort_strings(size2);
	}
	std::cout << '\n';
	{ // 3
		std::cout << "Generate strings (set)\n";
		constexpr size_t size1 = 500'000;
		constexpr size_t size2 = 5'000'000;

		set_generate_and_sort_strings(size1);
		set_generate_and_sort_strings(size2);
	}
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