#ifndef TASK_24_08_STDAFX
#include "Task_24_08_stdafx.h"
#include "Task_24_08_Gauss.h"
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

Vector operator*(const Matrix& m, const Vector& u)
{
	const auto n = m.size();
	Vector v(n);
	for (auto i = 0; i < n; ++i)
	{
		v[i] = std::inner_product(m[i].begin(), m[i].end(), u.begin(), 0.0);
	}
	return v;
}

Vector random_Vector(int n)
{
	Vector v(n);
	for (int i = 0; i < n; ++i)
	{
		v[i] = 1.0 * n * rand() / RAND_MAX;
	}
	return v;
}

Matrix random_matrix(int n)
{
	Matrix m(n);
	for (int i = 0; i < n; ++i)
	{
		m[i] = random_Vector(n);
	}
	return m;
}

void solve_random_system_classical(int n)
{
	std::cout << "Method - classical gaussian elimination\n";
	Matrix A = random_matrix(n);
	Vector b = random_Vector(n);
	print(A, b);
	try
	{
		Vector x = classical_gaussian_elimination_loop(A, b);
		std::cout << "x = " << x << "\n\n";
		Vector v = A * x;
		std::cout << "Check x :\n";
		std::cout << "A * x = " << v << '\n';
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void solve_random_system_pivotal(int n)
{
	std::cout << "Method - pivotal gaussian elimination\n";
	Matrix A = random_matrix(n);
	Vector b = random_Vector(n);
	print(A, b);
	try
	{
		Vector x = pivotal_elimination_loop(A, b);
		std::cout << "x = " << x << "\n\n";
		Vector v = A * x;
		std::cout << "Check x :\n";
		std::cout << "A * x = " << v << '\n';
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void classical_elimination_loop(Matrix& A, Vector& b)
{
	const int n = static_cast<int>(A.size());
	for (int j = 0; j < n - 1; ++j)
	{
		const double pivot = A[j][j];
		if (pivot == 0)
		{
			throw Elim_failure("Elimination failure in row " + j);
		}
		for (int i = j + 1; i < n; ++i)
		{
			const double mult = A[i][j] / pivot;
			for (int k = j; k < n; ++k)
			{
				A[i][k] -= A[j][k] * mult;
			}
			b[i] -= mult * b[j];
		}
	}
}

Vector back_substitution_loop(const Matrix& A, const Vector& b)
{
	const int n = static_cast<int>(A.size());
	Vector x(n);
	for (int i = n - 1; i >= 0; --i)
	{
		double s = b[i];
		for (int j = i + 1; j < n; ++j)
		{
			s -= A[i][j] * x[j];
		}
		if (double m = A[i][i])
		{
			x[i] = s / m;
		}
		else
		{
			throw Back_subst_failure("Back substitution failure in row " + i);
		}
	}
	return x;
}

void elim_with_partial_pivot_loop(Matrix& A, Vector& b)
{
	const int n = static_cast<int>(A.size());
	for (int j = 0; j < n; ++j)
	{
		int pivot_row = j;
		for (int k = j + 1; k < n; ++k)
		{
			if (abs(A[k][j]) > abs(A[pivot_row][j]))
			{
				pivot_row = k;
			}
		}
		if (pivot_row != j)
		{
			std::swap_ranges(A[j].begin(), A[j].end(), A[pivot_row].begin());
			std::swap(b[j], b[pivot_row]);
		}
		for (int i = j + 1; i < n; ++i)
		{
			const double pivot = A[j][j];
			if (pivot == 0)
			{
				throw std::runtime_error("No solution, pivot = 0");
			}
			const double mult = A[i][j] / pivot;
			for (int k = j; k < n; ++k)
			{
				A[i][k] -= A[j][k] * mult;
			}
			b[i] -= mult * b[j];
		}
	}
}

Vector classical_gaussian_elimination_loop(Matrix A, Vector b)
{
	classical_elimination_loop(A, b);
	return back_substitution_loop(A, b);
}

Vector pivotal_elimination_loop(Matrix A, Vector b)
{
	elim_with_partial_pivot_loop(A, b);
	return back_substitution_loop(A, b);
}

std::ostream& operator<<(std::ostream& outputStream, const Vector& vector)
{
	outputStream << "{ ";
	for (int i = 0; i < vector.size(); ++i)
	{
		outputStream << vector[i] << ' ';
	}
	outputStream << '}';
	return outputStream;
}

std::ostream& operator<<(std::ostream& outputStream, const Matrix& matrix)
{
	outputStream << "{\n";
	for (int i = 0; i < matrix.size(); ++i)
	{
		outputStream << matrix[i] << '\n';
	}
	outputStream << '}';
	return outputStream;
}

void print(const Matrix& A, const Vector& b)
{
	std::cout << "\n\n";
	for (int i = 0; i < A.size(); ++i)
	{
		std::cout << std::fixed << std::setw(5) << std::setprecision(3) << A[i] <<
			"{ " << std::fixed << std::setw(5) << std::setprecision(3) << b[i] << " }\n";
	}
	std::cout << "\n\n";
}