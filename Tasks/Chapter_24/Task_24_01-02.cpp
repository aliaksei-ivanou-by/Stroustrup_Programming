#include <iostream>
#include "Matrix.h"
#include "MatrixIO.h"

void tripleRef(int& n)
{
	n *= 3;
}

int tripleInt(int n)
{
	return n * 3;
}

int tripleIntRef(int& n)
{
	return n *= 3;
}

struct TripleRef // Modifies input parameter
{
	void operator()(int& n)
	{
		n *= 3;
	}
};

struct TripleInt // Doesn't modify input parameter
{
	int operator()(int n)
	{
		return n * 3;
	}
};

struct TripleIntRef // Modifies input parameter
{
	int operator()(int& n)
	{
		return n *= 3;
	}
};

int main()
try
{
	{
		constexpr int n = 5;
		Numeric_lib::Matrix<int, 1> matrix(n);
		int arr[n];
		for (int i = 0; i < n; ++i)
		{
			arr[i] = i + 1;
		}
		matrix = arr;

		// 1
		Numeric_lib::Matrix<int, 1> matrix1 = apply(tripleInt, matrix);
		std::cout << "apply(tripleInt, Matrix):\n" << matrix1 << '\n';

		Numeric_lib::Matrix<int, 1> matrix2 = matrix;
		matrix2.apply(tripleRef);
		std::cout << "Matrix.apply(tripleRef):\n" << matrix2 << '\n';

		// 2
		Numeric_lib::Matrix<int, 1> matrix3 = apply(tripleIntRef, matrix);
		std::cout << "apply(tripleIntRef, Matrix):\n" << matrix3 << '\n';

		Numeric_lib::Matrix<int, 1> matrix4 = matrix;
		matrix4.apply(tripleIntRef);
		std::cout << "Matrix.apply(tripleIntRef):\n" << matrix4 << '\n';
	}
	std::cout << '\n';
	{
		constexpr int n = 5;
		Numeric_lib::Matrix<int, 1> matrix(n);
		int arr[n];
		for (int i = 0; i < n; ++i)
		{
			arr[i] = i + 1;
		}
		matrix = arr;

		// 1
		Numeric_lib::Matrix<int, 1> matrix1 = apply(TripleInt(), matrix);
		std::cout << "apply(TripleInt(), Matrix):\n" << matrix1 << '\n';

		Numeric_lib::Matrix<int, 1> matrix2 = matrix;
		matrix2.apply(TripleRef());
		std::cout << "Matrix.apply(TripleRef()):\n" << matrix2 << '\n';

		// 2
		Numeric_lib::Matrix<int, 1> matrix3 = apply(TripleIntRef(), matrix);
		std::cout << "apply(TripleIntRef(), Matrix):\n" << matrix3 << '\n';

		Numeric_lib::Matrix<int, 1> matrix4 = matrix;
		matrix4.apply(TripleIntRef());
		std::cout << "Matrix.apply(TripleIntRef()):\n" << matrix4 << '\n';
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