#ifndef TASK_21_03_STDAFX_H
#define TASK_21_03_STDAFX_H

#include <iostream>
#include <vector>

#endif

template<typename Iterator, typename T>
unsigned int myCount(Iterator first, Iterator last, const T& value)
{
	unsigned int counter = 0;
	while (first != last)
	{
		if (*first++ == value)
		{
			++counter;
		}
	}
	return counter;
}