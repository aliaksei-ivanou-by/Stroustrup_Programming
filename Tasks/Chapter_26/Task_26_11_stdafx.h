#ifndef TASK_26_11_STDAFX_H
#define TASK_26_11_STDAFX_H

#include <iostream>
#include "Matrix.h"
#include "MatrixIO.h"
#include <vector>
#include <chrono>
#include <iomanip>

#endif

using Matrix = Numeric_lib::Matrix<double, 2>;
using Vector = Numeric_lib::Matrix<double, 1>;
using Numeric_lib::Index;

inline int rand_int(int max)
{
	return rand() % max;
}

inline int rand_int(int min, int max)
{
	return rand_int(max - min) + min;
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