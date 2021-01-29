#pragma once
#include <iostream>

template<class A>
class allocator
{
public:
	A* allocate(size_t n)
	{
		return reinterpret_cast<A*>(malloc(n * sizeof(A)));
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
	vector() :
		sz{ 0 },
		elem{ nullptr },
		space{ 0 }
	{}
	explicit vector(int n) :
		sz{ n },
		elem{ nullptr },
		space{ n }
	{
		elem = alloc.allocate(n);
		for (T* p = elem; p != elem + n; ++p)
		{
			alloc.construct(p, 0);
		}
	}
	vector(const vector& v) :
		sz{ v.sz },
		elem{ nullptr },
		space{ v.sz }
	{
		elem = alloc.allocate(v.sz);
		std::copy(v.elem, v.elem + v.sz, elem);
	}
	vector& operator=(const vector& v)
	{
		T* ptrTemp = alloc.allocate(v.sz);
		for (size_t i = 0; i < v.sz; ++i)
		{
			alloc.construct(&ptrTemp[i], v.elem[i]);
		}
		alloc.deallocate(elem);
		sz = v.sz;
		space = v.sz;
		elem = ptrTemp;
		return *this;
	}
	vector(vector&& vv) :
		sz{ vv.sz },
		elem{ vv.elem },
		space{ vv.space }
	{
		vv.sz = 0;
		vv.elem = nullptr;
	}
	vector& operator=(vector&& vv)
	{
		alloc.deallocate(elem);
		elem = vv.elem;
		sz = vv.sz;
		space = vv.space;

		vv.sz = 0;
		vv.elem = nullptr;
		vv.space = 0;
		return *this;
	}
	~vector()
	{
		for (T* p = elem; p != elem + sz; ++p)
		{
			alloc.destroy(p);
		}
		alloc.deallocate(elem);
	}
	T& at(int n)
	{
		if ((n < 0) || (sz < n))
		{
			throw std::out_of_range("");
		}
		return elem[n];
	}
	const T& at(int n) const
	{
		if ((n < 0) || (sz < n))
		{
			throw std::out_of_range("");
		}
		return elem[n];
	}
	T& operator[](int n)
	{
		return elem[n];
	}
	const T& operator[](int n) const
	{
		return elem[n];
	}
	int size() const
	{
		return sz;
	}
	int capacity() const
	{
		return space;
	}
	void reserve(int newalloc)
	{
		if (newalloc <= space)
		{
			return;
		}
		T* p = alloc.allocate(newalloc);
		for (int i = 0; i < sz; ++i)
		{
			p[i] = elem[i];
		}
		alloc.deallocate(elem);
		elem = p;
		space = newalloc;
	}
	void push_back(const T& val)
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
	void resize(int newsize, T val = T())
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
	void push_front(const T& val)
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
		for (int i = sz; i > 0; --i)
		{
			alloc.construct(&elem[i], elem[i - 1]);
			alloc.destroy(&elem[i - 1]);
		}
		alloc.construct(&elem[0], val);
		++sz;
	}
};