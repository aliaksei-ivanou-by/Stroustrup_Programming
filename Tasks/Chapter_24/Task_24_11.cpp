#ifndef TASK_24_11_STDAFX_H
#include "Task_24_11_stdafx.h"
#endif

int main()
try
{
	srand(static_cast<unsigned int>(time(NULL)));

	int n;
	std::cout << "Enter size for Matrix : \n";
	std::cin >> n;
	Matrix A = random_Matrix(n);
	std::cout << "A = " << std::fixed << std::setprecision(3) << A << '\n';

	A.swap_rows(0, 1);
	std::cout << "swap rows(0, 1)\n";
	std::cout << "A = " << std::fixed << std::setprecision(3) << A << '\n';

	A.swap_columns(0, 1);
	std::cout << "swap columns(0, 1)\n";
	std::cout << "A = " << std::fixed << std::setprecision(3) << A << '\n';
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