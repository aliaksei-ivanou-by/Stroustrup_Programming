#ifndef TASK_14_15_ITERATOR_H
#define TASK_14_15_ITERATOR_H

#ifndef TASK_14_15_STDAFX_H
#include "Task_14_15_stdafx.h"
#endif

class Iterator
{
public:
	virtual double* next() = 0;
	virtual int size() const = 0;
};

void print(Iterator& it);

#endif