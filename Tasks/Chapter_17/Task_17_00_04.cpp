#include <iostream>
#include <vector>
#include <cmath>

void print_array(std::ostream& os, int* a, int n)
{
	for (int i = 0; i < n; ++i)
	{
		os << a[i] << ' ';
	}
	os << '\n';
}

void print_vector(std::ostream& os, std::vector<int> v)
{
	for (int i = 0; i < static_cast<int>(v.size()); ++i)
	{
		os << v[i] << ' ';
	}
	os << '\n';
}

int main()
{
	// 1
	int x1 = 7;
	int* p1 = &x1;

	// 2
	std::cout << "p1 = " << p1 << '\n';
	std::cout << "*p1 = " << *p1 << '\n';

	// 3
	int* p2 = new int[7];
	for (int i = 0; i < 7; ++i)
	{
		p2[i] = pow(2, i);
	}

	// 4
	std::cout << "p2 = " << p2 << '\n';
	std::cout << "*p2 = ";
	print_array(std::cout, p2, 7);

	// 5
	int* p3 = p2;

	// 6
	p2 = p1;

	// 7
	p2 = p3;

	// 8
	std::cout << "p1 = " << p1 << '\n';
	std::cout << "*p1 = " << *p1 << '\n';
	std::cout << "p2 = " << p2 << '\n';
	std::cout << "*p2 = " << *p2 << '\n';

	// 9
	delete[] p3;
	p2 = nullptr;

	// 10
	p1 = new int[10];
	for (int i = 0; i < 10; ++i)
	{
		p1[i] = pow(2, i);
	}

	// 11
	p2 = new int[10];

	// 12
	for (int i = 0; i < 10; ++i)
	{
		p2[i] = p1[i];
	}
	print_array(std::cout, p2, 10);

	// 13
	std::vector<int> v1;
	for (int i = 0; i < 10; ++i)
	{
		v1.push_back(pow(2, i));
	}
	std::vector<int> v2;
	for (int i = 0; i < static_cast<int>(v1.size()); ++i)
	{
		v2.push_back(v1[i]);
	}
	print_vector(std::cout, v2);
}