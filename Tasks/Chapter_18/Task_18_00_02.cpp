#include <iostream>

class vector
{
	int sz;
	double* elem;
public:
	explicit vector(int s)
		: sz{ s },
		elem{ new double[s] }
	{
		for (int i = 0; i < sz; ++i)
		{
			elem[i] = 0.0;
		}
	}

	vector(const vector& arg)
		: sz{ arg.sz },
		elem{ new double[arg.sz] }
	{
		std::copy(arg.elem, arg.elem + sz, elem);
	}

	vector(vector&& arg)
		: sz{ arg.sz },
		elem{ arg.elem }
	{
		arg.sz = 0;
		arg.elem = nullptr;
	}

	friend void swap(vector& first, vector& second)
	{
		std::swap(first.sz, second.sz);
		std::swap(first.elem, second.elem);
	}

	/*
	vector& operator=(const vector& arg)
	{
		double* p = new double[arg.sz];
		std::copy(arg.elem, arg.elem + arg.sz, p);
		delete[] elem;
		elem = p;
		sz = arg.sz;
		return *this;
	}

	vector& operator=(vector&& arg)
	{
		delete[] elem;
		elem = arg.elem;
		sz = arg.sz;
		arg.elem = nullptr;
		arg.sz = 0;
		return *this;
	}
	*/

	vector& operator=(vector arg)
	{
		swap(*this, arg);
		return *this;
	}

	double& operator[](int n)
	{
		return elem[n];
	}

	double operator[](int n) const
	{
		return elem[n];
	}

	~vector()
	{
		delete[] elem;
	}

	int size() const
	{
		return sz;
	}
};

int main()
try
{
	vector v(10);
	int x = v[2];
	std::cout << "x = " << x << '\n';
	x = 5;
	v[3] = x;
	std::cout << "v[3] = " << v[3] << '\n';

	vector v1(2);
	v1[0] = 1;
	v1[1] = 2;
	vector v2(2);
	v2[0] = 3;
	v2[1] = 4;
	std::cout << "v1 : ";
	for (int i = 0; i < v1.size(); ++i)
	{
		std::cout << v1[i] << ' ';
	}
	std::cout << '\n';
	std::cout << "v2 : ";
	for (int i = 0; i < v2.size(); ++i)
	{
		std::cout << v2[i] << ' ';
	}
	std::cout << '\n';
	std::cout << "v1 = v2\n";
	v1 = v2;
	std::cout << "v1 : ";
	for (int i = 0; i < v1.size(); ++i)
	{
		std::cout << v1[i] << ' ';
	}
	std::cout << '\n';
	std::cout << "v2 : ";
	for (int i = 0; i < v2.size(); ++i)
	{
		std::cout << v2[i] << ' ';
	}
	std::cout << '\n';
}
catch (const std::exception& e)
{
	std::cout << "Exception occured: " << e.what() << '\n';
	return 1;
}
catch (...)
{
	return 2;
}