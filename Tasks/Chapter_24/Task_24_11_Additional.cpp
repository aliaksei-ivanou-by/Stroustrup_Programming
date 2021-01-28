#ifndef TASK_24_11_STDAFX_H
#include "Task_24_11_stdafx.h"
#include "Task_24_11_Additional.h"
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