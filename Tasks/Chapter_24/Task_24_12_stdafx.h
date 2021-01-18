#ifndef TASK_24_12_STDAFX_H
#define TASK_24_12_STDAFX_H

#include <iostream>
#include "Matrix.h"
#include "MatrixIO.h"
#include <random>
#include <iomanip>

#endif

using Matrix = Numeric_lib::Matrix<double, 2>;
using Vector = Numeric_lib::Matrix<double, 1>;
using Numeric_lib::Index;

Vector random_Vector(Index n)
{
	Vector v(n);
	for (Index i = 0; i < n; ++i)
	{
		v(i) = 1.0 * n * rand() / RAND_MAX;
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

namespace Numeric_lib
{
	Matrix<double> operator*(const Matrix<double, 2>& matrixLeft, const Matrix<double>& matrixRight)
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
	Matrix<double, N> operator+(Matrix<double, N>& matrixLeft, Matrix<double, N>& matrixRight)
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