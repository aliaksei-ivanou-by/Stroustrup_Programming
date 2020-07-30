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
	//double operator[](int n)
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