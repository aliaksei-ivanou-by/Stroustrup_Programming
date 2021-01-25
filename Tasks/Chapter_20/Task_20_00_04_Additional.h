#ifndef TASK_20_00_04_ADDITIONAL_H
#define TASK_20_00_04_ADDITIONAL_H

#ifndef TASK_20_00_04_STDAFX_H
#include "Task_20_00_04_stdafx.h"
#endif

template<class Iterator>
Iterator high(Iterator first, Iterator last)
{
	if (first == last)
	{
		throw std::runtime_error("Container hasn't got highest element");
	}
	Iterator high = first;
	for (Iterator p = first; p != last; ++p)
	{
		if (*high < *p)
		{
			high = p;
		}
	}
	return high;
}

double* get_from_jack(int* count);
std::vector<double>* get_from_jill();
void fct();

#endif