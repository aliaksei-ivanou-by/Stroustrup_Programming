#ifndef TASK_24_00_03_STDAFX_H
#define TASK_24_00_03_STDAFX_H

#include <iostream>
#include "Matrix.h"
#include "MatrixIO.h"
#include <iomanip>
#include <complex>
#include <numeric>

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