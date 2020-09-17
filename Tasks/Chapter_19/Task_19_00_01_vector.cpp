#ifndef TASK_19_00_01_STDAFX
#include "Task_19_00_01_stdafx.h"
#include "Task_19_00_01_vector.h"
#endif

vector::vector():
	sz{ 0 },
	elem{ nullptr },
	space{ 0 }
{}

size_t vector::size() const
{
	return sz;
}

void vector::reserve(int newalloc)
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

void vector::resize(int newsize)
{
	reserve(newsize);
	for (int i = sz; i < newsize; ++i)
	{
		elem[i] = 0;
	}
	sz = newsize;
}

int vector::capacity() const
{
	return space;
}