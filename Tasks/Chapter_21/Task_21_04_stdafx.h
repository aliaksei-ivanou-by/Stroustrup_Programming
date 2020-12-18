#ifndef TASK_21_04_STDAFX_H
#define TASK_21_04_STDAFX_H

#include <iostream>
#include <vector>

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