#ifndef TASK_19_05_STDAFX_H
#include "Task_19_05_stdafx.h"
#endif

int main(int argc, char** argv)
try
{
	Number x{ 500 };
	Number y{ 100 };
	Number z{ 0 };
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