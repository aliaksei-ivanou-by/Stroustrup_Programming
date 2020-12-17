#ifndef TASK_20_00_03_STDAFX_H
#define TASK_20_00_03_STDAFX_H

#include <iostream>

#endif

void copy(int* f1, int* e1, int* f2)
{
	while (f1 != e1)
	{
		*(f2++) = *(f1++);
	}
}