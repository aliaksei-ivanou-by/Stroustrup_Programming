#ifndef TASK_14_15_VECTOR_ITERATOR_H
#include "Task_14_15_stdafx.h"
#include "Task_14_15_Vector_iterator.h"
#endif

double* Vector_iterator::next()
{
	if (v_size > 0)
	{
		return &(*v_current++);
	}
	else
	{
		return nullptr;
	}
}

Vector_iterator::Vector_iterator(std::vector<double>& vv)
	: v_begin{ vv.begin() }, v_end{ vv.end() }, v_size{ static_cast<int>(vv.size()) }
{
	v_current = v_begin;
}

int Vector_iterator::size() const
{
	return v_size;
}
