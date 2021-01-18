#ifndef TASK_24_11_STDAFX_H
#define TASK_24_11_STDAFX_H

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

/*
in Matrix.h : 
void swap_columns(Index i, Index j)
{
	if (i == j)
	{
		return;
	}
	Index max = dim1();
	for (Index k = 0; k < max; ++k)
	{
		std::swap((*this)(k, i), (*this)(k, j));
	}
}
*/