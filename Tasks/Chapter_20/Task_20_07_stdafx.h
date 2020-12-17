#ifndef TASK_20_07_STDAFX_H
#define TASK_20_07_STDAFX_H

#include <iostream>
#include <vector>
#include <string>

#endif

template<typename Iterator1, typename Iterator2>
auto findLast(Iterator1 first, Iterator2 last)
{
	Iterator1 high = first;
	while (first != last)
	{
		if (*first > *high)
		{
			high = first;
		}
		++first;
	}
	return high;
}