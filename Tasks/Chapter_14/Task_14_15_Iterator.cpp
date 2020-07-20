#ifndef TASK_14_15_ITERATOR_H
#include "Task_14_15_stdafx.h"
#include "Task_14_15_Iterator.h"
#endif

void print(Iterator& it)
{
	for (int i = 0; i < it.size(); ++i)
	{
		std::cout << *it.next() << '\n';
	}
}