#ifndef TASK_24_05_STDAFX_H
#include "Task_24_05_stdafx.h"
#endif

int main()
try
{
	double arr_A[2][2] = { { 0, 1 }, { 1, 0} };
	double arr_b[2] = { 5, 6 };

	Matrix A(2, 2);
	A[0] = arr_A[0];
	A[1] = arr_A[1];

	Vector b(2);
	b = arr_b;

	std::cout << "A = \n" << A << '\n';
	std::cout << "b = \n" << b << '\n';

	Vector x(2);

	std::cout << "pivotal_elimination\n";
	try
	{
		x = pivotal_elimination(A, b);
	}
	catch (std::runtime_error& r)
	{
		std::cerr << "Runtime error::" << r.what();
	}
	std::cout << "x = " << x << '\n';
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