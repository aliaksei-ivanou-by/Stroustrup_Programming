#include <iostream>
#include "Matrix.h"
#include "MatrixIO.h"
#include <random>
#include <iomanip>
#include "Task_24_Matrix_Additional.h"

using Matrix = Numeric_lib::Matrix<double, 2>;
using Vector = Numeric_lib::Matrix<double, 1>;

int main()
try
{
	srand(static_cast<unsigned int>(time(NULL)));

	int n;
	std::cout << "Enter size for Vector and Matrix for operation * : \n";
	std::cin >> n;
	Matrix A = random_Matrix(n);
	Vector B = random_Vector(n);
	std::cout << "A = " << std::fixed << std::setprecision(3) << A << '\n';
	std::cout << "B = " << std::fixed << std::setprecision(3) << B << '\n';
	
	std::cout << "A * B = :\n";
	std::cout << std::fixed << std::setprecision(3) << A * B << '\n';

	std::cout << "\n\n";

	int m;
	std::cout << "Enter size for Matrixes for operation + : \n";
	std::cin >> m;
	Matrix C = random_Matrix(m);
	Matrix D = random_Matrix(m);

	std::cout << "C = " << std::fixed << std::setprecision(3) << C << '\n';
	std::cout << "D = " << std::fixed << std::setprecision(3) << D << '\n';

	std::cout << "C + D = " << std::fixed << std::setprecision(3) << C + D << '\n';
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