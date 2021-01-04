#ifndef TASK_19_16_VECTOR_H
#define TASK_19_16_VECTOR_H

#ifndef TASK_19_16_STDAFX_H
#include "Task_19_16_stdafx.h"
#endif

template<typename T>
class vector
{
private:
	T* elem;
	int sz;
	int space;
public:
	vector() :
		elem{ nullptr },
		sz{ 0 },
		space{ 0 }
	{}
	vector(int n) :
		elem{ std::make_unique<T[]>(n).release() },
		sz{ n },
		space{ n }
	{
		if (!elem)
		{
			throw std::bad_alloc;
		}
		T temp = T();
		for (int i = 0; i < sz; ++i)
		{
			elem[i] = temp;
		}
	}
	int size()
	{
		return sz;
	}
	int capacity()
	{
		return space;
	}
};

template<typename T>
class vectorShort
{
private:
	vector<T>* v;
public:
	vectorShort() :
		v{ std::make_unique<vector<T>>().release() }
	{
		if (!v)
		{
			throw std::bad_alloc;
		}
	}
	vectorShort(int n) :
		v{ std::make_unique<vector<T>>(n).release() }
	{
		if (!v)
		{
			throw std::bad_alloc;
		}
	}
	int size()
	{
		return v->sz;
	}
	int capacity()
	{
		return v->space;
	}
	~vectorShort()
	{
		delete v;
	}
};

#endif