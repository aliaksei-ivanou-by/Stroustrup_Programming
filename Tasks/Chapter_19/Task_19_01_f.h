#ifndef TASK_19_01_F_H
#define TASK_19_01_F_H

#ifndef TASK_19_01_STDAFX_H
#include "Task_19_01_stdafx.h"
#endif

template<class T>
void f(std::vector<T>& vectorFirst, const std::vector<T>& vectorSecond)
{
	if (vectorFirst.size() > vectorSecond.size())
	{
		throw std::runtime_error("size of v1 > size of v2");
	}
	for (size_t i = 0; i < vectorFirst.size(); ++i)
	{
		vectorFirst[i] += vectorSecond[i];
	}
}

#endif