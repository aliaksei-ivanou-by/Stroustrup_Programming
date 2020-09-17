#ifndef TASK_19_00_01_VECTOR_H
#define TASK_19_00_01_VECTOR_H

#ifndef TASK_19_00_01_STDAFX_H
#include "Task_19_00_01_stdafx.h"
#endif

class vector
{
	int sz;
	double* elem;
	int space;
public:
	vector();
	size_t size() const;
	void reserve(int newalloc);
	void resize(int newsize);
	int capacity() const;
};
#endif