#ifndef TASK_24_04_GAUSS_H
#define TASK_24_04_GAUSS_H

#ifndef TASK_24_04_STDAFX_H
#include "Task_24_04_stdafx.h"
#endif

using Matrix = Numeric_lib::Matrix<double, 2>;
using Vector = Numeric_lib::Matrix<double, 1>;
using Numeric_lib::Index;

struct Elim_failure;
struct Back_subst_failure;

void classical_elimination(Matrix& A, Vector& b);
Vector back_substitution(const Matrix& A, const Vector& b);
void elim_with_partial_pivot(Matrix& A, Vector& b);

Vector classical_gaussian_elimination(Matrix A, Vector b);
Vector pivotal_elimination(Matrix A, Vector b);

Vector operator*(const Matrix& m, const Vector& u);
Vector random_Vector(Index n);
Matrix random_matrix(Index n);

void solve_random_system_classical(Index n);
void solve_random_system_pivotal(Index n);

#endif