#include <iostream>
#include "Matrix.h"
#include "MatrixIO.h"
#include <random>
#include <iomanip>
#include "Task_24_Matrix_Additional.h"

using Matrix = Numeric_lib::Matrix<double, 2>;

/*
in Matrix.h :
void swap_columns(Index i, Index j)
{
	if (i == j)
	{
		return;
	}
	Index max = dim1();
	for (Index k = 0; k < max; ++k)
	{
		std::swap((*this)(k, i), (*this)(k, j));
	}
}
*/

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