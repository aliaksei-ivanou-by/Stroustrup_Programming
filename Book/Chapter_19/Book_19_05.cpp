#include <iostream>

template<class T> // requires Element<T>()
class vector
{
	int sz;
	T* elem;
	int space;
public:
	vector()
		: sz{ 0 },
		elem{ nullptr },
		space{ 0 }
	{
	}

	explicit vector(int s)
		: sz{ s },
		elem{ new T[s] },
		space{ s }
	{
		for (int i = 0; i < sz; ++i)
		{
			elem[i] = 0;
		}
	}

	vector(std::initializer_list<T> lst)
		: sz{ static_cast<int>(lst.size()) },
		elem{ new double[sz] }
	{
		std::copy(lst.begin(), lst.end(), elem);
	}

	vector(const vector& a);

	vector& operator=(const vector&& a);

	~vector()
	{
		delete[] elem;
	}

	T& operator[](int n)
	{
		return elem[n];
	}

	const T& operator[](int n) const
	{
		return elem[n];
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
		T* p = new T[newalloc];
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
	
	void push_back(T d)
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
		T* p = new T[a.sz];
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
	vector<double> v_d;
	vector<int> v_i;
	vector<double*> v_d_ptr;
	vector<vector<int>> v_v_i;
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