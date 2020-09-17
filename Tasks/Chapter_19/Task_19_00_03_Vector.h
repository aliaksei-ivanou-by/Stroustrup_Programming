#ifndef TASK_19_00_03_VECTOR_H
#define TASK_19_00_03_VECTOR_H

#ifndef TASK_19_00_03_STDAFX_H
#include "Task_19_00_03_stdafx.h"
#endif

template<class A>
class allocator
{
public:
	A* allocate(int n)
	{
		return (A*)malloc(n * sizeof(A));
	}
	void deallocate(A* p)
	{
		free(p);
	}
	void construct(A* p, const A& v)
	{
		new(p) A{ v };
	}
	void destroy(A* p)
	{
		p->~A();
	}
};

template<class T, class A = allocator<T>>
class vector
{
private:
	int sz;
	T* elem;
	int space;
	A alloc;
public:
	vector();
	explicit vector(int n);
	vector(const vector& v);
	vector& operator=(const vector& v);
	vector(vector&& vv);
	vector& operator=(vector&& vv);
	~vector();
	T& at(int n);
	const T& at(int n) const;
	T& operator[](int n);
	const T& operator[](int n) const;
	int size() const;
	int capacity() const;
	void reserve(int newalloc);
	void push_back(const T& val);
	void resize(int newsize, T val = T());
};

template<class T, class A>
vector<T, A>::vector()
	: sz{ 0 },
	elem{ nullptr },
	space{ 0 }
{
}

template<class T, class A>
vector<T, A>::vector(int n)
	: sz{ n },
	elem{ nullptr },
	space{ n }
{
	elem = alloc.allocate(n);
	for (T* p = elem; p != elem + n; ++p)
	{
		alloc.construct(p, 0);
	}
}

template<class T, class A>
vector<T, A>::vector(const vector<T, A>& v)
	: sz{ v.sz },
	elem{ nullptr },
	space{ v.sz }
{
	elem = alloc.allocate(v.sz);
	std::copy(v.elem, v.elem + v.sz, elem);
}

template<class T, class A>
vector<T, A>& vector<T, A>::operator=(const vector<T, A>& v)
{
	if (this == &v)
	{
		return *this;
	}
	if (v.sz <= space)
	{
		for (int i = 0; i < v.sz; ++i)
		{
			elem[i] = v.elem[i];
		}
		for (int i = v.sz; i < sz; ++i)
		{
			alloc.destroy(&elem[i]);
		}
		sz = v.sz;
		return *this;
	}
	T* p = alloc.allocate(v.sz);
	std::copy(v.elem, v.elem + v.sz, p);
	for (T* q = elem; q != elem + sz; ++q)
	{
		alloc.destroy(q);
	}
	alloc.deallocate(elem);
	space = sz = v.sz;
	elem = p;
	return *this;
}

template<class T, class A>
vector<T, A>::vector(vector<T, A>&& vv)
	: sz{ vv.sz },
	elem{ vv.elem },
	space{ vv.space }
{
	vv.sz = 0;
	vv.elem = nullptr;
}

template<class T, class A>
vector<T, A>& vector<T, A>::operator=(vector<T, A>&& vv)
{
	for (T* p = elem; p != elem + sz; ++p)
	{
		alloc.destroy(p);
	}
	alloc.deallocate(elem);
	elem = vv.elem;
	sz = vv.sz;
	space = vv.space;
	vv.sz = 0;
	vv.elem = nullptr;
	return *this;
}

template<class T, class A>
vector<T, A>::~vector()
{
	for (T* p = elem; p != elem + sz; ++p)
	{
		alloc.destroy(p);
	}
	alloc.deallocate(elem);
}
template<class T, class A>
T& vector<T, A>::at(int n)
{
	if ((n < 0) || (sz < n))
	{
		throw std::out_of_range("");
	}
	return elem[n];
}

template<class T, class A>
const T& vector<T, A>::at(int n) const
{
	if ((n < 0) || (sz < n))
	{
		throw std::out_of_range("");
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

template<class T, class A>
int vector<T, A>::size() const
{
	return sz;
}

template<class T, class A>
int vector<T, A>::capacity() const
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
	T* p = (std::unique_ptr<T>(new T[newalloc])).release();
	for (int i = 0; i < sz; ++i)
	{
		p[i] = elem[i];
	}
	delete[] elem;
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

#endif