#ifndef TASK_21_05_FUNC_H
#define TASK_21_05_FUNC_H

#ifndef TASK_21_05_STDAFX_H
#include "Task_21_05_stdafx.h"
#endif

template<typename In, typename T>
bool myFind(In& first, In last, const T& val)
{
	while (first != last)
	{
		if (*first == val)
		{
			return true;
		}
		++first;
	}
	return false;
}

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

#endif