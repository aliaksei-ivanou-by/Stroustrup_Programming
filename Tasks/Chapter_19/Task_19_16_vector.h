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
		elem{ new T[n] },
		sz{ n },
		space{ n }
	{
		if (!elem)
		{
			delete[] elem;
			throw("Bad allocation");
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
		v{ new vector<T>() }
	{
		if (!v)
		{
			throw("Bad allocation");
		}
	}
	vectorShort(int n) :
		v{ new vector<T>(n) }
	{
		if (!v)
		{
			throw("Bad allocation");
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