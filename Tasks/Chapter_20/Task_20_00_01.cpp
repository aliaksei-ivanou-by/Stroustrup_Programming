#ifndef TASK_20_00_01_H
#include "Task_20_00_01.h"
#endif

double* high(double* first, double* last)
{
	double h = -1;
	double* high;
	for (double* p = first; p != last; ++p)
	{
		if (h < *p)
		{
			high = p;
			h = *p;
		}
	}
	return high;
}
