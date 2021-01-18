#ifndef TASK_24_08_GAUSS_H
#define TASK_24_08_GAUSS_H

#ifndef TASK_24_08_STDAFX_H
#include "Task_24_08_stdafx.h"
#endif

using Matrix = std::vector<std::vector<double>>;
using Vector = std::vector<double>;

struct Elim_failure;
struct Back_subst_failure;

void classical_elimination_loop(Matrix& A, Vector& b);
Vector back_substitution_loop(const Matrix& A, const Vector& b);
void elim_with_partial_pivot_loop(Matrix& A, Vector& b);

Vector classical_gaussian_elimination_loop(Matrix A, Vector b);
Vector pivotal_elimination_loop(Matrix A, Vector b);

Vector operator*(const Matrix& m, const Vector& u);
Vector random_Vector(int n);
Matrix random_matrix(int n);

void solve_random_system_classical(int n);
void solve_random_system_pivotal(int n);

std::ostream& operator<<(std::ostream& outputStream, const Vector& vector);
std::ostream& operator<<(std::ostream& outputStream, const Matrix& matrix);

void print(const Matrix& A, const Vector& b);

#endif