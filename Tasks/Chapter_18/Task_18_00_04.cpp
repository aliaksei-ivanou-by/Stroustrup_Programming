#include <iostream>
#include "vector"

// 1
std::vector<int> gv = { 1, 2, 4, 8, 16, 32, 64, 128, 256, 512 };

// 2
void f(std::vector<int> v);

int factorial(int n);

int main()
try
{
	// 4.1
	f(gv);

	// 4.2
	std::vector<int> vv;
	for (int i = 0; i < 10; ++i)
	{
		vv.push_back(factorial(i));
	}

	// 4.3
	f(vv);
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
void f(std::vector<int> v)
{
	// 3.1, 3.2
	std::vector<int> lv(gv);

	// 3.3
	for (const auto& i : lv)
	{
		std::cout << i << ' ';
	}
	std::cout << '\n';

	// 3.4
	std::vector<int> lv2(v);

	// 3.5
	for (const auto& i : lv2)
	{
		std::cout << i << ' ';
	}
	std::cout << '\n';
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