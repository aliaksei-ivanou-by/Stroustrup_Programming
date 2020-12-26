#ifndef TASK_21_07_STDAFX_H
#define TASK_21_07_STDAFX_H

#include <iostream>
#include <vector>
#include <list>
#include <string>

#endif

template<typename Iter, typename T>
bool myBinarySearch(Iter first, Iter last, const T& val)
{
	if (first == last)
	{
		return false;
	}
	if (*(--last) < val)
	{
		return false;
	}
	Iter low = first;
	Iter high = last;
	while (true)
	{
		if (low == high)
		{
			return false;
		}
		int distance = 0;
		Iter f = low;
		while (f != high)
		{
			++f;
			++distance;
		}
		Iter lowTemp = low;
		std::advance(lowTemp, distance / 2);
		Iter mid = lowTemp;
		T guess = *mid;
		if (guess == val)
		{
			return true;
		}
		if (guess > val)
		{
			--mid;
			high = mid;
		}
		else
		{
			++mid;
			low = mid;
		}
	}
	return false;
}