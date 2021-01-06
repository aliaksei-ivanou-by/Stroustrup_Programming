Matrix<int, 1> a1(8);
Matrix<int> a(8);

a.size();
a.dim1();

int* p = a.data();

a(i);
a[i];

a.slice(i);
a.slice(i, n);

a.slice(4, 8) = a.slice(0, 4);
a.slice(4) = a.slice(0, 4);

Matrix<int> a2 = a;
a = a2;

a *= 7;
a = 7;

a.apply(f);
a.apply(f, 7);

b = apply(abc, a);

b = a * 7;
a * = 7; // a =b
y = apply(f, x);
x.apply(f); // x = y

b = apply(f, a, x);

double scale(double d, double s)
{
	return d * s;
}
b = apply(scale, a, 7);

void scale_in_place(double& d, double s)
{
	d *= s;
}
b = apply(scale_in_place, 7);

Matrix<int> a3 = scale_and_add(a, 8, a2); // result(i) = arg1(i) * arg2 + arg3(i)
int r = dot_product(a3, a);

void some_function(double* p, int n)
{
	double val[] = { 1.2, 2.3, 3.4, 4.5 };
	Matrix<double> data{ p, n };
	Matrix<double> constants{ val };
	// ...