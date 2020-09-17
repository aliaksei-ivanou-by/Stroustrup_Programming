#include <iostream>

class vector
{
	int sz;
	double* elem;
	int space;
public:
	vector()
		: sz{ 0 },
		elem{ nullptr },
		space{ 0 }
	{
	}

	size_t size()
	{
		return sz;
	}

	void reserve(int newalloc)
	{
		if (newalloc <= space)
		{
			return;
		}
		double* p = new double[newalloc];
		for (int i = 0; i < sz; ++i)
		{
			p[i] = elem[i];
		}
		delete[] elem;
		elem = p;
		space = newalloc;
	}

	void resize(int newsize)
	{
		reserve(newsize);
		for (int i = sz; i < newsize; ++i)
		{
			elem[i] = 0;
		}
		sz = newsize;
	}

	int capacity() const
	{
		return space;
	}
	
	void push_back(double d)
	{
		if (space == 0)
		{
			reserve(8);
		}
		else
		{
			if (sz == space)
			{
				reserve(2 * space);
			}
		}
		elem[sz] = d;
		++sz;
	}

	vector& operator=(const vector& a)
	{
		if (this == &a)
		{
			return *this;
		}
		if (a.sz < space)
		{
			for (int i = 0; i < a.sz; ++i)
			{
				elem[i] = a.elem[i];
			}
			sz = a.sz;
			return *this;
		}	
		double* p = new double[a.sz];
		for (int i = 0; i < a.sz; ++i)
		{
			p[i] = a.elem[i];
		}
		delete[] elem;
		space = sz = a.sz;
		elem = p;
		return *this;
	}
};

int main()
try
{

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