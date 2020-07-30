#include <iostream>

// 1
int ga[10] = { 1, 2, 4, 8, 16, 32, 64, 128, 256, 512 };

// 2
void f(int a[], int n);

int factorial(int n);

int main()
try
{
	// 4
	size_t ga_sz = sizeof(ga) / sizeof(int);
	f(ga, ga_sz);

	// 5
	constexpr size_t aa_sz = 10;
	int aa[aa_sz];
	for (int i = 0; i < aa_sz; ++i)
	{
		aa[i] = factorial(i);
	}

	// 6
	f(aa, aa_sz);
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

// 3
void f(int arr[], int n)
{
	// 3.1
	int la[10];
	// 3.2
	for (int i = 0; i < n; ++i)
	{
		la[i] = ga[i];
	}
	// 3.3
	for (const auto& i : la)
	{
		std::cout << i << ' ';
	}
	std::cout << '\n';

	// 3.4
	int* p = new int[n];

	// 3.5
	for (int i = 0; i < n; ++i)
	{
		p[i] = arr[i];
	}

	// 3.6
	for (int i = 0; i < n; ++i)
	{
		std::cout << *(p + i) << ' ';
	}
	std::cout << '\n';

	// 3.7
	delete[] p;
}

int factorial(int n)
{
	if (n < 0)
	{
		return 1;
	}
	if (n == 0)
	{
		return 1;
	}
	else
	{
		return n * factorial(n - 1);
	}
}