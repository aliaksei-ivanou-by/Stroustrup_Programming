#ifndef BOOK_19_06_STDAFX
#include "Book_19_06_stdafx.h"
#include "Book_19_06_Vector.h"
#endif

template<class T, class A>
vector<T, A>::vector()
	: sz{ 0 },
	elem{ nullptr },
	space{ 0 }
{
}

template<class T, class A>
vector<T, A>::vector(int s)
	: sz{ s },
	elem{ new T[s] },
	space{ s }
{
	for (int i = 0; i < sz; ++i)
	{
		elem[i] = 0;
	}
}

template<class T, class A>
vector<T, A>::vector(std::initializer_list<T> lst)
	: sz{ static_cast<int>(lst.size) },
	elem{ new double[sz] }
{
	std::copy(lst.begin(), lst.end(), elem);
}

template<class T, class A>
vector<T, A>::~vector()
{
	delete[] elem;
}

template<class T, class A>
const size_t vector<T, A>::size() const
{
	return sz;
}

template<class T, class A>
const int vector<T, A>::capacity() const
{
	return space;
}

template<class T, class A>
void vector<T, A>::reserve(int newalloc)
{
	if (newalloc <= space)
	{
		return;
	}
	T* p = alloc.allocate(newalloc);
	for (int i = 0; i < sz; ++i)
	{
		alloc.construct(&p[i], elem[i]);
	}
	for (int i = 0; i < sz; ++i)
	{
		alloc.destroy(&elem[i]);
	}
	alloc.deallocate(elem, space);
	elem = p;
	space = newalloc;
}

template<class T, class A>
void vector<T, A>::push_back(const T& val)
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
	alloc.construct(&elem[sz], val);
	++sz;
}

template<class T, class A>
void vector<T, A>::resize(int newsize, T val)
{
	reserve(newsize);
	for (int i = sz; i < newsize; ++i)
	{
		alloc.construct(&elem[i], val);
	}
	for (int i = newsize; i < sz; ++i)
	{
		alloc.destroy(&elem[i]);
	}
	sz = newsize;
}

template<class T, class A>
T& vector<T, A>::at(int n)
{
	if ((n < 0) || (sz <= n))
	{
		throw std::out_of_range("Error: out_of_range\n");
	}
	return elem[n];
}

template<class T, class A>
const T& vector<T, A>::at(int n) const
{
	if ((n < 0) || (sz <= n))
	{
		throw std::out_of_range("Error: out_of_range\n");
	}
	return elem[n];
}

template<class T, class A>
T& vector<T, A>::operator[](int n)
{
	return elem[n];
}

template<class T, class A>
const T& vector<T, A>::operator[](int n) const
{
	return elem[n];
}

void print_some(vector<int>& v)
{
	int i = -1;
	while ((std::cin >> i) && (i != -1))
	{
		try
		{
			std::cout << "v[" << i << "] = " << v.at(i) << '\n';
		}
		catch(std::out_of_range())
		{
			std::cout << "Wrong range: " << i << '\n';
		}
	}
}