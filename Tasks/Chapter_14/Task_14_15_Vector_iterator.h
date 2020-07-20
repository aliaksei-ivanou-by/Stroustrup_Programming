#ifndef TASK_14_15_VECTOR_ITERATOR_H
#define TASK_14_15_VECTOR_ITERATOR_H

#ifndef TASK_14_15_STDAFX_H
#include "Task_14_15_stdafx.h"
#endif

class Vector_iterator : public Iterator
{
public:
	double* next();
	Vector_iterator(std::vector<double>& vv);
	int size() const;
private:
	std::vector<double>::iterator v_begin;
	std::vector<double>::iterator v_current;
	std::vector<double>::iterator v_end;
	int v_size;
};

#endif