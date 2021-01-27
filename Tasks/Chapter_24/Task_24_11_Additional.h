#ifndef TASK_24_11_ADDITIONAL_H
#define TASK_24_11_ADDITIONAL_H

#ifndef TASK_24_11_STDAFX_H
#include "Task_24_11_stdafx.h"
#endif

using Matrix = Numeric_lib::Matrix<double, 2>;
using Vector = Numeric_lib::Matrix<double, 1>;
using Numeric_lib::Index;

Vector random_Vector(Index n);
Matrix random_Matrix(Index n);

/*
in Matrix.h :
void swap_columns(Index i, Index j);
*/

#endif