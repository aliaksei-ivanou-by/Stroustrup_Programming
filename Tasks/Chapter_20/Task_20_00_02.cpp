#ifndef TASK_20_00_02_H
#include "Task_20_00_02.h"
#endif

double* high(double* first, double* last)
{
	double* high = first;
	for (double* p = first; p != last; ++p)
	{
		if (*high < *p)
		{
			high = p;
		}
	}
	return high;
}
