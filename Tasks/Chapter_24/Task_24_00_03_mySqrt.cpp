#ifndef TASK_24_00_03_STDAFX
#include "Task_24_00_03_stdafx.h"
#include "Task_24_00_03_mySqrt.h"
#endif

void mySqrt()
{
	int number;
	std::cin >> number;
	if (number <= 0)
	{
		std::cout << "no sqrt\n";
	}
	else
	{
		std::cout << "sqrt = " << sqrt(number) << '\n';
	}
}