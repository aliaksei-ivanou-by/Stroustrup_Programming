#ifndef TASK_14_15_LIST_ITERATOR_H
#include "Task_14_15_stdafx.h"
#include "Task_14_15_List_iterator.h"
#endif

double* List_iterator::next()
{
	if (l_size > 0)
	{
		return &(*l_current++);
	}
	else
	{
		return nullptr;
	}
}

List_iterator::List_iterator(std::list<double>& ll)
	: l_begin{ ll.begin() }, l_end{ ll.end() }, l_size{ static_cast<int>(ll.size()) }
{
	l_current = l_begin;
}

int List_iterator::size() const
{
	return l_size;
}
