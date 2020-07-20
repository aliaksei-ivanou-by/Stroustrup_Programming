#ifndef TASK_14_15_LIST_ITERATOR_H
#define TASK_14_15_LIST_ITERATOR_H

#ifndef TASK_14_15_STDAFX_H
#include "Task_14_15_stdafx.h"
#endif

class List_iterator : public Iterator
{
public:
	double* next();
	List_iterator(std::list<double>& ll);
	int size() const;
private:
	std::list<double>::iterator l_begin;
	std::list<double>::iterator l_current;
	std::list<double>::iterator l_end;
	int l_size;
};

#endif