#include <iostream>
#include "Matrix.h"
#include "MatrixIO.h"
#include <iomanip>
#include <complex>
#include <numeric>

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

int main()
try
{
	// 1
	std::cout << "sizeof char = " << sizeof(char) << '\n';
	std::cout << "sizeof short = " << sizeof(short) << '\n';
	std::cout << "sizeof long = " << sizeof(long) << '\n';
	std::cout << "sizeof float = " << sizeof(float) << '\n';
	std::cout << "sizeof double = " << sizeof(double) << '\n';
	std::cout << "sizeof int* = " << sizeof(int*) << '\n';
	std::cout << "sizeof double* = " << sizeof(double*) << '\n';

	std::cout << "\n\n";

	// 2
	Numeric_lib::Matrix<int> a(10);
	std::cout << "sizeof Matrix<int> a(10) = " << sizeof(a) << '\n';
	Numeric_lib::Matrix<int> b(10);
	std::cout << "sizeof Matrix<int> b(10) = " << sizeof(b) << '\n';
	Numeric_lib::Matrix<double> c(10);
	std::cout << "sizeof Matrix<double> c(10) = " << sizeof(c) << '\n';
	Numeric_lib::Matrix<int, 2> d(10, 10);
	std::cout << "sizeof Matrix<int, 2> d(10, 10) = " << sizeof(d) << '\n';
	Numeric_lib::Matrix<int, 3> e(10, 10, 10);
	std::cout << "sizeof Matrix<int, 3> e(10, 10, 10) = " << sizeof(e) << '\n';
	
	std::cout << "\n\n";

	// 3
	std::cout << "size Matrix<int> a(10) = " << a.size() << '\n';
	std::cout << "size Matrix<int> b(10) = " << b.size() << '\n';
	std::cout << "size Matrix<double> c(10) = " << c.size() << '\n';
	std::cout << "size Matrix<int, 2> d(10, 10) = " << d.size() << '\n';
	std::cout << "size Matrix<int, 3> e(10, 10, 10) = " << e.size() << '\n';

	std::cout << "\n\n";

	// 4
	std::cout << "Enter 10 ints for sqrt:\n";
	for (int i = 0; i < 5; ++i)
	{
		mySqrt();
	}

	std::cout << "\n\n";

	// 5
	std::cout << "Enter 10 doubles for entry into a Matrix:\n";
	const int numbers = 10;
	Numeric_lib::Matrix<double> md(numbers);
	for (int i = 0; i < numbers; ++i)
	{
		std::cin >> md[i];
	}
	std::cout << md << '\n';

	std::cout << "\n\n";
	
	// 6
	std::cout << "Enter the dimensions for the table (m, n): ";
	int m;
	int n;
	std::cin >> m >> n;
	Numeric_lib::Matrix<double, 2> table1(m, n);
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (i == 0 || j == 0)
			{
				table1(i, j) = i + j;
			}
			else
			{
				table1(i, j) = i * j;
			}
		}
	}
	for (int i = 0; i < table1.dim1(); ++i)
	{
		for (int j = 0; j < table1.dim2(); ++j)
		{
			std::cout << std::setw(5) << table1(i, j);
		}
		std::cout << '\n';
	}

	std::cout << "\n\n";

	// 7
	std::cout << "Enter 10 complex numbers:\n";
	Numeric_lib::Matrix<std::complex<double>> table2(10);
	for (int i = 0; i < table2.size(); ++i)
	{
		std::cin >> table2[i];
	}
	std::cout << std::accumulate(table2.data(), table2.data() + table2.size(), std::complex<double>{});

	std::cout << "\n\n";

	// 8
	std::cout << "Enter 6 ints for Matrix:\n";
	Numeric_lib::Matrix<int, 2> table3(2, 3);
	for (int i = 0; i < table3.dim1(); ++i)
	{
		for (int j = 0; j < table3.dim2(); ++j)
		{
			std::cin >> table3[i][j];
		}
	}
	std::cout << table3;
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