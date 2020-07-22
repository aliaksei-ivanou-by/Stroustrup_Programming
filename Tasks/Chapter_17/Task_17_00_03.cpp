#include <iostream>
#include <vector>

// 4
void print_array10(std::ostream& os, const int* a)
{
	for (size_t i = 0; i < 10; ++i)
	{
		os << a[i] << ' ';
	}
	os << '\n';
}

// 7
void print_array(std::ostream& os, const int* a, const size_t n)
{
	for (size_t i = 0; i < n; ++i)
	{
		os << a[i] << ' ';
	}
	os << '\n';
}

// 10
void print_vector(std::ostream& os, const std::vector<int>& v)
{
	for (size_t i = 0; i < v.size(); ++i)
	{
		os << v[i] << ' ';
	}
	os << '\n';
}

int main()
{
	// 1
	int* arr1 = new int[10];
	for (size_t i = 0; i < 10; ++i)
	{
		arr1[i] = i;
	}

	// 2
	for (size_t i = 0; i < 10; ++i)
	{
		std::cout << arr1[i] << ' ';
	}
	std::cout << '\n';

	// 3
	delete[] arr1;

	// 5
	int* arr2 = new int[10];
	for (size_t i = 0; i < 10; ++i)
	{
		arr2[i] = 100 + i;
	}
	print_array10(std::cout, arr2);

	// 6
	int* arr3 = new int[11];
	for (size_t i = 0; i < 11; ++i)
	{
		arr3[i] = 100 + i;
	}
	for (size_t i = 0; i < 11; ++i)
	{
		std::cout << arr3[i] << ' ';
	}
	std::cout << '\n';

	// 8
	int* arr4 = new int[20];
	for (size_t i = 0; i < 20; ++i)
	{
		arr4[i] = 100 + i;
	}
	print_array(std::cout, arr4, 20);

	// 9
	delete[] arr2;
	delete[] arr3;
	delete[] arr4;

	// 10.5
	std::vector<int> v1;
	for (size_t i = 0; i < 10; ++i)
	{
		v1.push_back(100 + i);
	}
	print_vector(std::cout, v1);

	// 10.6
	std::vector<int> v2;
	for (size_t i = 0; i < 11; ++i)
	{
		v2.push_back(100 + i);
	}
	print_vector(std::cout, v2);

	// 10.8
	std::vector<int> v3;
	for (size_t i = 0; i < 20; ++i)
	{
		v3.push_back(100 + i);
	}
	print_vector(std::cout, v3);
}