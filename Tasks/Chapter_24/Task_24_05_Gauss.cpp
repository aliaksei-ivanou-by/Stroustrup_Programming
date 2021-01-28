#ifndef TASK_24_05_STDAFX_H
#include "Task_24_05_stdafx.h"
#include "Task_24_05_Gauss.h"
#endif

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

Vector classical_gaussian_elimination(Matrix A, Vector b)
{
	classical_elimination(A, b);
	return back_substitution(A, b);
}

Vector pivotal_elimination(Matrix A, Vector b)
{
	elim_with_partial_pivot(A, b);
	return back_substitution(A, b);
}

void classical_elimination(Matrix& A, Vector& b)
{
	const Index n = A.dim1();
	for (Index j = 0; j < n - 1; ++j)
	{
		const double pivot = A(j, j);
		if (pivot == 0)
		{
			throw Elim_failure("Elimination failure in row " + std::to_string(j));
		}
		for (Index i = j + 1; i < n; ++i)
		{
			const double mult = A(i, j) / pivot;
			A[i].slice(j) = Numeric_lib::scale_and_add(A[j].slice(j), -mult, A[i].slice(j));
			b(i) -= mult * b(j);
		}
	}
}

Vector back_substitution(const Matrix& A, const Vector& b)
{
	const Index n = A.dim1();
	Vector x(n);
	for (Index i = n - 1; i >= 0; --i)
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

void elim_with_partial_pivot(Matrix& A, Vector& b)
{
	const Index n = A.dim1();
	for (Index j = 0; j < n; ++j)
	{
		Index pivot_row = j;
		for (Index k = j + 1; k < n; ++k)
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
		for (Index i = j + 1; i < n; ++i)
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

Vector operator*(const Matrix& m, const Vector& u)
{
	const Index n = m.dim1();
	Vector v(n);
	for (Index i = 0; i < n; ++i)
	{
		v(i) = Numeric_lib::dot_product(m[i], u);
	}
	return v;
}

Vector random_Vector(Index n)
{
	Vector v(n);
	for (Index i = 0; i < n; ++i)
	{
		v(i) = 1.0 * n * rand() / RAND_MAX;
	}
	return v;
}

Matrix random_matrix(Index n)
{
	Matrix m(n, n);
	for (Index i = 0; i < n; ++i)
	{
		m[i] = random_Vector(n);
	}
	return m;
}

void solve_random_system_classical(Index n)
{
	Matrix A = random_matrix(n);
	Vector b = random_Vector(n);
	std::cout << "A = " << A << '\n';
	std::cout << "b = " << b << '\n';
	try
	{
		Vector x = classical_gaussian_elimination(A, b);
		std::cout << "classical elim solution is x = " << x << '\n';
		Vector v = A * x;
		std::cout << " A * x = " << v << '\n';
		std::cout << '\n';
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void solve_random_system_pivotal(Index n)
{
	Matrix A = random_matrix(n);
	Vector b = random_Vector(n);
	std::cout << "A = " << A << '\n';
	std::cout << "b = " << b << '\n';
	try
	{
		Vector x = pivotal_elimination(A, b);
		std::cout << "pivotal elim solution is x = " << x << '\n';
		Vector v = A * x;
		std::cout << " A * x = " << v << '\n';
		std::cout << '\n';
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}