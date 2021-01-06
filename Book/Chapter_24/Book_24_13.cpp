typedef Numeric_lib::Matrix<double, 2> Matrix;
typedef Numeric_lib::Matrix<double, 1> Vector;

Vector classical_gaussian_elimination(Matrix A, Vector b)
{
	classical_elimination(A, b);
	return back_substitution(A, b);
}

void classical_elimination(Matrix& A, Vector& b)
{
	const Index n = A.dim1();
	for (Index j = 0; j < n - 1; ++j)
	{
		const double pivot = A(j, j);
		if (pivot == 0)
		{
			throw Elim_failure(j);
		}
		for (Index i = j + 1; i < n; ++i)
		{
			const double mult = A(i, j) / pivot;
			A[i].slice(j) = scale_and_add(A[j].slice(j), -mult, A[i].slice(j));
			b(i) -= mult * b(j);
		}
	}
}

Vector back_substitution(const Matrix& A, const Vector& b)
{
	const Index n = A.dim1();
	Vector x(n);
	for (Index i = n - 1; i > = 0; --i)
	{
		double s = b(i) - dot_product(A[i].slice(i + 1), x.slice(i + 1));
		if (double m = A(i, i))
		{
			x(i) = s / m;
		}
		else
		{
			throw Back_subst_failure(i);
		}
	}
	return x;
}

void elim_with_partial_pivot(Matrix& A, Vector& b)
{
	const Index n = A.dim1();
	for (Index j = 0; j < n; ++j)
	{
		Index pivot_row = j;
		for (Index k = j + 1; k < n; ++k)
		{
			if (abs(A(k, j)) > abs(A(pivot_row, j)))
			{
				pivot_row = k;
			}
		}
		if (pivot_row != j)
		{
			A.swap_rows(j, pivot_row);
			std::swap(b(j), b(pivot_row));
		}
		
		for (Index i = j + 1; i < n; ++i)
		{
			const double pivot = A(j, j);
			if (pivot == 0)
			{
				error("No solution, zero pivot");
			}
			const double mult = A(i, j) / pivot;
			A[i].slice(j) = scale_and_add(A[j].slice(j), -milt, A[i],slice(j));
			b(i) -= mult * b(j);
		}
	}
}

void sole_random_system(Index n)
{
	Matrix A = random_matrix(n);
	Vector b = random_vector(n);
	
	cout << "A = " << A << '\n';
	cout << "b = " << b << '\n';
	
	try
	{
		Vector x = classical_gaussian_elimination(A, b);
		cout << "Solution by Gauss: x = " << x << '\n';
		Vector v = A * x;
		cout << "A * x" << v << '\n';
	}
	catch(const exception& e)
	{
		cerr << e.what() << '\n';
	}
}

Vector operator*(const Matrix& m, const Vector& u)
{
	const Index n = m.dim1();
	Vector v(n);
	for (Index i = 0; i < n; ++i)
	{
		v(i) = dot_product(m[i], u);
	}
	return v;
}

Vector random_vector(Index n)
{
	Vector v(n);
	default_random_engine ran();
	uniform_real_distribution<> ureal(0, max);
	for (Index i = 0; i < n; ++i)
	{
		v(i) = ureal(ran);
	}
	return v;
}