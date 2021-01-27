#ifndef TASK_21_00_01_FIND_H
#define TASK_21_00_01_FIND_H

#ifndef TASK_21_00_01_STDAFX_H
#include "Task_21_00_01_stdafx.h"
#endif

template<typename In, typename T>
In find1(In first, In last, const T& val)
{
	while (first != last && *first != val)
	{
		++first;
	}
	return first;
}

template<typename In, typename T>
In find2(In first, In last, const T& val)
{
	for (In p = first; p != last; ++p)
	{
		if (*p == val)
		{
			return p;
		}
	}
	return last;
}

#endif