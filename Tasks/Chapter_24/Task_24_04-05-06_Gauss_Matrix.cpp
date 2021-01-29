#include <iostream>
#include "Matrix.h"
#include "MatrixIO.h"
#include <random>
#include "Task_24_Matrix_Additional.h"

using Matrix = Numeric_lib::Matrix<double, 2>;
using Vector = Numeric_lib::Matrix<double, 1>;

int main()
try
{
	{ // random
		solve_random_system_classical(3);
		solve_random_system_classical(4);
		solve_random_system_classical(5);

		solve_random_system_pivotal(3);
		solve_random_system_pivotal(4);
		solve_random_system_pivotal(5);
	}
	
	{ // A = {{0, 1}{1, 0}}, B = {5, 6}
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
	{ // loop dot_product() and scale_and_add()
		solve_random_system_classical_loop(3);
		solve_random_system_classical_loop(4);
		solve_random_system_classical_loop(5);

		solve_random_system_pivotal_loop(3);
		solve_random_system_pivotal_loop(4);
		solve_random_system_pivotal_loop(5);
	}
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