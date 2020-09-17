#ifndef TASK_19_02_F_H
#define TASK_19_02_F_H

#ifndef TASK_19_02_STDAFX_H
#include "Task_19_02_stdafx.h"
#endif

template<class C, class A, class B>
C f(std::vector<A>& vectorFirst, const std::vector<B>& vectorSecond)
{
	if (vectorFirst.size() != vectorSecond.size())
	{
		throw std::runtime_error("size of first vector != size of second vector");
	}
	C sum = 0;
	for (size_t i = 0; i < vectorFirst.size(); ++i)
	{
		sum += vectorFirst[i] + vectorSecond[i];
	}
	return sum;
}

#endif