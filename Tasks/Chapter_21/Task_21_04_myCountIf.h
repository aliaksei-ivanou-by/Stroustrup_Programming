#ifndef TASK_21_04_MYCOUNTIF_H
#define TASK_21_04_MYCOUNTIF_H

#ifndef TASK_21_04_STDAFX_H
#include "Task_21_04_stdafx.h"
#endif

template<typename Iterator, typename Predicate>
unsigned int myCountIf(Iterator first, Iterator last, Predicate predicate)
{
	unsigned int counter = 0;
	while (first != last)
	{
		if (predicate(*first++))
		{
			++counter;
		}
	}
	return counter;
}

#endif