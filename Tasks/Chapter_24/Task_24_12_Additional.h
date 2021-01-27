#ifndef TASK_24_12_ADDITIONAL_H
#define TASK_24_12_ADDITIONAL_H

#ifndef TASK_24_12_STDAFX_H
#include "Task_24_12_stdafx.h"
#endif

using Matrix = Numeric_lib::Matrix<double, 2>;
using Vector = Numeric_lib::Matrix<double, 1>;
using Numeric_lib::Index;

Vector random_Vector(Index n);
Matrix random_Matrix(Index n);

namespace Numeric_lib
{
	Matrix<double> operator*(const Matrix<double, 2>& matrixLeft, const Matrix<double>& matrixRight);

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

#endif