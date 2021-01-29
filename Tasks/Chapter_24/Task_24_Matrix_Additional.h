#pragma once
#include <iostream>
#include "Matrix.h"
#include "MatrixIO.h"

Numeric_lib::Matrix<double, 1> random_Vector(
	Numeric_lib::Index n)
{
	Numeric_lib::Matrix<double, 1> v(n);
	for (Numeric_lib::Index i = 0; i < n; ++i)
	{
		v(i) = 1.0 * n * rand() / RAND_MAX;
	}
	return v;
}

Numeric_lib::Matrix<double, 2> random_Matrix(
	Numeric_lib::Index n)
{
	Numeric_lib::Matrix<double, 2> m(n, n);
	for (Numeric_lib::Index i = 0; i < n; ++i)
	{
		m[i] = random_Vector(n);
	}
	return m;
}

namespace Numeric_lib
{
	Matrix<double> operator*(
		const Matrix<double, 2>& matrixLeft,
		const Matrix<double>& matrixRight)
	{
		if (matrixLeft.dim1() != matrixRight.dim1() ||
			matrixLeft.dim2() != matrixRight.dim1())
		{
			throw std::runtime_error("Vector sizes are not suitable for the operation");
		}
		Matrix<double> result(matrixRight.size());
		for (Index i = 0; i < result.size(); ++i)
		{
			result(i) = dot_product(matrixLeft[i], matrixRight);
		}
		return result;
	}

	template<int N>
	Matrix<double, N> operator+(
		Matrix<double, N>& matrixLeft,
		Matrix<double, N>& matrixRight)
	{
		if (matrixLeft.dim1() != matrixRight.dim1() ||
			matrixLeft.dim2() != matrixRight.dim2())
		{
			throw std::runtime_error("Vector sizes are not suitable for the operation");
		}
		Matrix<double, N> result = matrixLeft;
		for (Index i = 0; i < matrixLeft.size(); ++i)
		{
			result.data()[i] += matrixRight.data()[i];
		}
		return result;
	}
}

/*
in Matrix.h :
void swap_columns(Numeric_lib::Index i, Numeric_lib::Index j)
{
	if (i == j)
	{
		return;
	}
	Numeric_lib::Index max = dim1();
	for (Numeric_lib::Index k = 0; k < max; ++k)
	{
		std::swap((*this)(k, i), (*this)(k, j));
	}
}
*/

struct Elim_failure : std::domain_error
{
	Elim_failure(std::string s) : std::domain_error(s)
	{}
};

struct Back_subst_failure : std::domain_error
{
	Back_subst_failure(std::string s) : std::domain_error(s)
	{}
};

void classical_elimination(
	Numeric_lib::Matrix<double, 2>& A,
	Numeric_lib::Matrix<double, 1>& b)
{
	const Numeric_lib::Index n = A.dim1();
	for (Numeric_lib::Index j = 0; j < n - 1; ++j)
	{
		const double pivot = A(j, j);
		if (pivot == 0)
		{
			throw Elim_failure("Elimination failure in row " + std::to_string(j));
		}
		for (Numeric_lib::Index i = j + 1; i < n; ++i)
		{
			const double mult = A(i, j) / pivot;
			A[i].slice(j) = Numeric_lib::scale_and_add(A[j].slice(j), -mult, A[i].slice(j));
			b(i) -= mult * b(j);
		}
	}
}

Numeric_lib::Matrix<double, 1> back_substitution(
	const Numeric_lib::Matrix<double, 2>& A,
	const Numeric_lib::Matrix<double, 1>& b)
{
	const Numeric_lib::Index n = A.dim1();
	Numeric_lib::Matrix<double, 1> x(n);
	for (Numeric_lib::Index i = n - 1; i >= 0; --i)
	{
		double s = b(i) - Numeric_lib::dot_product(A[i].slice(i + 1), x.slice(i + 1));
		if (double m = A(i, i))
		{
			x(i) = s / m;
		}
		else
		{
			throw Back_subst_failure("Back substitution failure in row " + std::to_string(i));
		}
	}
	return x;
}

void elim_with_partial_pivot(
	Numeric_lib::Matrix<double, 2>& A,
	Numeric_lib::Matrix<double, 1>& b)
{
	const Numeric_lib::Index n = A.dim1();
	for (Numeric_lib::Index j = 0; j < n; ++j)
	{
		Numeric_lib::Index pivot_row = j;
		for (Numeric_lib::Index k = j + 1; k < n; ++k)
		{
			if (abs(A(k, j)) > abs(A(pivot_row, j)))
			{
				pivot_row = k;
			}
		}
		if (pivot_row != j)
		{
			A.swap_rows(j, pivot_row);
			std::swap(b(j), b(pivot_row));
		}
		for (Numeric_lib::Index i = j + 1; i < n; ++i)
		{
			const double pivot = A(j, j);
			if (pivot == 0)
			{
				throw std::runtime_error("No solution, pivot = 0");
			}
			const double mult = A(i, j) / pivot;
			A[i].slice(j) = Numeric_lib::scale_and_add(A[j].slice(j), -mult, A[i].slice(j));
			b(i) -= mult * b(j);
		}
	}
}

void classical_elimination_loop(
	Numeric_lib::Matrix<double, 2>& A,
	Numeric_lib::Matrix<double, 1>& b)
{
	const Numeric_lib::Index n = A.dim1();
	for (Numeric_lib::Index j = 0; j < n - 1; ++j)
	{
		const double pivot = A(j, j);
		if (pivot == 0)
		{
			throw Elim_failure("Elimination failure in row " + std::to_string(j));
		}
		for (Numeric_lib::Index i = j + 1; i < n; ++i)
		{
			const double mult = A(i, j) / pivot;
			for (Numeric_lib::Index k = j; k < n; ++k)
			{
				A(i, k) -= A(j, k) * mult;
			}
			b(i) -= mult * b(j);
		}
	}
}

Numeric_lib::Matrix<double, 1> back_substitution_loop(
	const Numeric_lib::Matrix<double, 2>& A,
	const Numeric_lib::Matrix<double, 1>& b)
{
	const Numeric_lib::Index n = A.dim1();
	Numeric_lib::Matrix<double, 1> x(n);
	for (Numeric_lib::Index i = n - 1; i >= 0; --i)
	{
		double s = b(i);
		for (Numeric_lib::Index j = i + 1; j < n; ++j)
		{
			s -= A(i, j) * x(j);
		}
		if (double m = A(i, i))
		{
			x(i) = s / m;
		}
		else
		{
			throw Back_subst_failure("Back substitution failure in row " + std::to_string(i));
		}
	}
	return x;
}

void elim_with_partial_pivot_loop(
	Numeric_lib::Matrix<double, 2>& A,
	Numeric_lib::Matrix<double, 1>& b)
{
	const Numeric_lib::Index n = A.dim1();
	for (Numeric_lib::Index j = 0; j < n; ++j)
	{
		Numeric_lib::Index pivot_row = j;
		for (Numeric_lib::Index k = j + 1; k < n; ++k)
		{
			if (abs(A(k, j)) > abs(A(pivot_row, j)))
			{
				pivot_row = k;
			}
		}
		if (pivot_row != j)
		{
			A.swap_rows(j, pivot_row);
			std::swap(b(j), b(pivot_row));
		}
		for (Numeric_lib::Index i = j + 1; i < n; ++i)
		{
			const double pivot = A(j, j);
			if (pivot == 0)
			{
				throw std::runtime_error("No solution, pivot = 0");
			}
			const double mult = A(i, j) / pivot;
			for (Numeric_lib::Index k = j; k < n; ++k)
			{
				A(i, k) -= A(j, k) * mult;
			}
			b(i) -= mult * b(j);
		}
	}
}

Numeric_lib::Matrix<double, 1> classical_gaussian_elimination(
	Numeric_lib::Matrix<double, 2> A,
	Numeric_lib::Matrix<double, 1> b)
{
	classical_elimination(A, b);
	return back_substitution(A, b);
}

Numeric_lib::Matrix<double, 1> pivotal_elimination(
	Numeric_lib::Matrix<double, 2> A,
	Numeric_lib::Matrix<double, 1> b)
{
	elim_with_partial_pivot(A, b);
	return back_substitution(A, b);
}

Numeric_lib::Matrix<double, 1> classical_gaussian_elimination_loop(
	Numeric_lib::Matrix<double, 2> A,
	Numeric_lib::Matrix<double, 1> b)
{
	classical_elimination_loop(A, b);
	return back_substitution_loop(A, b);
}

Numeric_lib::Matrix<double, 1> pivotal_elimination_loop(
	Numeric_lib::Matrix<double, 2> A,
	Numeric_lib::Matrix<double, 1> b)
{
	elim_with_partial_pivot_loop(A, b);
	return back_substitution_loop(A, b);
}

void solve_random_system_classical(Numeric_lib::Index n)
{
	Numeric_lib::Matrix<double, 2> A = random_Matrix(n);
	Numeric_lib::Matrix<double, 1> b = random_Vector(n);
	std::cout << "A = " << A << '\n';
	std::cout << "b = " << b << '\n';
	try
	{
		Numeric_lib::Matrix<double, 1> x = classical_gaussian_elimination(A, b);
		std::cout << "classical elim solution is x = " << x << '\n';
		Numeric_lib::Matrix<double, 1> v = A * x;
		std::cout << " A * x = " << v << '\n';
		std::cout << '\n';
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void solve_random_system_pivotal(Numeric_lib::Index n)
{
	Numeric_lib::Matrix<double, 2> A = random_Matrix(n);
	Numeric_lib::Matrix<double, 1> b = random_Vector(n);
	std::cout << "A = " << A << '\n';
	std::cout << "b = " << b << '\n';
	try
	{
		Numeric_lib::Matrix<double, 1> x = pivotal_elimination(A, b);
		std::cout << "pivotal elim solution is x = " << x << '\n';
		Numeric_lib::Matrix<double, 1> v = A * x;
		std::cout << " A * x = " << v << '\n';
		std::cout << '\n';
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void solve_random_system_classical_loop(Numeric_lib::Index n)
{
	Numeric_lib::Matrix<double, 2> A = random_Matrix(n);
	Numeric_lib::Matrix<double, 1> b = random_Vector(n);
	std::cout << "A = " << A << '\n';
	std::cout << "b = " << b << '\n';
	try
	{
		Numeric_lib::Matrix<double, 1> x = classical_gaussian_elimination_loop(A, b);
		std::cout << "classical elim solution loop is x = " << x << '\n';
		Numeric_lib::Matrix<double, 1> v = A * x;
		std::cout << " A * x = " << v << '\n';
		std::cout << '\n';
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void solve_random_system_pivotal_loop(Numeric_lib::Index n)
{
	Numeric_lib::Matrix<double, 2> A = random_Matrix(n);
	Numeric_lib::Matrix<double, 1> b = random_Vector(n);
	std::cout << "A = " << A << '\n';
	std::cout << "b = " << b << '\n';
	try
	{
		Numeric_lib::Matrix<double, 1> x = pivotal_elimination_loop(A, b);
		std::cout << "pivotal elim solution loop is x = " << x << '\n';
		Numeric_lib::Matrix<double, 1> v = A * x;
		std::cout << " A * x = " << v << '\n';
		std::cout << '\n';
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}