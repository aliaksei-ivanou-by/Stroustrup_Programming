#ifndef TASK_20_05_STDAFX_H
#include "Task_20_05_stdafx.h"
#endif

int main()
try
{
	std::vector<int> vectorInt;
	std::vector<double> vectorDouble;

	std::cout << "Enter vectorInt : ";
	std::cin >> vectorInt;
	std::cout << "vectorInt is : " << vectorInt;

	std::cout << '\n';

	std::cout << "Enter vectorDouble : ";
	std::cin >> vectorDouble;
	std::cout << "vectorDouble is : " << vectorDouble;
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