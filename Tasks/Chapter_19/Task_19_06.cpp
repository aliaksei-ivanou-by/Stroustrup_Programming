#ifndef TASK_19_06_STDAFX_H
#include "Task_19_06_stdafx.h"
#endif

int main(int argc, char** argv)
try
{
	Number<int> x{ 500 };
	Number<int> y{ 100 };
	Number<int> z{ 0 };
	std::cout << "x = " << x << '\n'
		<< "y = " << y << '\n'
		<< "z = " << z << '\n';
	x = x + x;
	y = y - 1;
	z = x / y;
	std::cout << "x = " << x << '\n'
		<< "y = " << y << '\n'
		<< "z = " << z << '\n';
	std::cin >> x;
	std::cin >> y;
	std::cin >> z;
	std::cout << "x = " << x << '\n'
		<< "y = " << y << '\n'
		<< "z = " << z << '\n';
	Number<int> a{ 25 };
	Number<double> b{ 3.14 };
	// std::cout << b % a;
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