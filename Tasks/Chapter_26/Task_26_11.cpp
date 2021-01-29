#include <iostream>
#include "Matrix.h"
#include "MatrixIO.h"
#include <vector>
#include <chrono>
#include <iomanip>

using Matrix = Numeric_lib::Matrix<double, 2>;
using Vector = Numeric_lib::Matrix<double, 1>;
using Numeric_lib::Index;

inline int rand_int(int min, int max)
{
	return (rand() % (max - min) + min);
}

Vector random_Vector(Index n)
{
	Vector v(n);
	for (Index i = 0; i < n; ++i)
	{
		v(i) = rand_int(-10, 10);
	}
	return v;
}

Matrix random_Matrix(Index n)
{
	Matrix m(n, n);
	for (Index i = 0; i < n; ++i)
	{
		m[i] = random_Vector(n);
	}
	return m;
}

double row_sum(const Matrix& m, int n)
{
	double s = 0;
	for (Index i = 0; i < m.dim2(); ++i)
	{
		s += m(n, i);
	}
	return s;
}

double row_accum(const Matrix& m, int n)
{
	double s = 0;
	for (Index i = 0; i < n; ++i)
	{
		s += row_sum(m, i);
	}
	return s;
}

int main()
try
{
	srand(static_cast<unsigned int>(time(NULL)));
	std::vector<int> size = { 100, 10'000, 1'000'000, 10'000'000 };

	{
		// 1
		auto timeStart = std::chrono::system_clock::now();
		std::cout << "First method\n";
		for (const auto& i : size)
		{
			auto timeStart = std::chrono::system_clock::now();

			Matrix m = random_Matrix(i);
			std::vector<double>* vec = std::make_unique<std::vector<double>>().release();
			for (Index idx = 0; idx < m.dim1(); ++idx)
			{
				vec->push_back(row_accum(m, idx + 1));
			}

			auto timeFinish = std::chrono::system_clock::now();
			std::cout << std::setw(15) << i << '\t' <<
				std::chrono::duration_cast<std::chrono::milliseconds>(timeFinish - timeStart).count() << "ms";

			std::cout << "\n";
		}
	}
	std::cout << '\n';
	{
		// 2
		auto timeStart = std::chrono::system_clock::now();
		std::cout << "Second method\n";
		for (const auto& i : size)
		{
			auto timeStart = std::chrono::system_clock::now();

			Matrix m = random_Matrix(i);
			std::vector<double>* vec = std::make_unique<std::vector<double>>().release();
			double s = 0;
			for (Index j = 0; j < m.dim1(); ++j)
			{
				s += row_sum(m, j);
				vec->push_back(s);
			}

			auto timeFinish = std::chrono::system_clock::now();
			std::cout << std::setw(15) << i << '\t' <<
				std::chrono::duration_cast<std::chrono::milliseconds>(timeFinish - timeStart).count() << "ms";

			std::cout << "\n";
		}
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