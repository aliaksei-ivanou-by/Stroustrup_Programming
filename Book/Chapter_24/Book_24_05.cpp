#include "Matrix.h"
using namespace Numeric_lib;

void f1(int n1, int n2, int n3)
{
	Matrix<double, 1> ad1(n1);
	Matrix<int, 1> ai1(n1);
	ad1(7) = 0;
	ad1[7] = 8;
	Matrix<double, 2> ad2(n1, n2);
	Matrix<double, 3> ad3(n1, n2, n3);
	ad2(3, 4) = 7.5;
	ad3(3, 4, 5) = 9.2;
}

void f2(int n1, int n2, int n3)
{
	Matrix<int, 0> ai0;
	Matrix<double, 1> ad1(5);
	Matrix<int, 1> ai(5);	
	Matrix<double, 1> ad11(7);
	
	ad1(7) = 0;
	ad1 = ai;
	ad1 = ad11;
	
	Matrix<double, 2> ad2(n1);
	
	ad2(3) = 7.5;
	ad2(1, 2, 3) = 7.5;
	
	Matrix<double, 3> ad3(n1, n2, n3);
	Matrix<double, 3> ad33(n1, n2, n3);
	ad3 = ad33; // OK
}

void init(Matrix<int, 2>& a)
{
	for (int i = 0; i < a.dim1(); ++i)
	{
		for (int j = 0; j < a.dim2(); ++j)
		{
			a(i, j) = 10 * i + j;
		}
	}
}

void print(const Matrix<int, 2>& a)
{
	for (int i = 0; i < a.dim1(); ++i)
	{
		for (int j = 0; j < a.dim2(); ++j)
		{
			cout << a(i, j) << '\t';
		}
		cout << '\n';
	}
}