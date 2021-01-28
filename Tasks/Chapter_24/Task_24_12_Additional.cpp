#ifndef TASK_24_12_STDAFX_H
#include "Task_24_12_stdafx.h"
#include "Task_24_12_Additional.h"
#endif

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
		Numeric_lib::Matrix<double> result(matrixRight.size());
		for (Index i = 0; i < result.size(); ++i)
		{
			result(i) = dot_product(matrixLeft[i], matrixRight);
		}
		return result;
	}
}