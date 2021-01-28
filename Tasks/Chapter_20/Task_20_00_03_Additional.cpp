#ifndef TASK_20_00_03_STDAFX_H
#include "Task_20_00_03_stdafx.h"
#include "Task_20_00_03_Additional.h"
#endif

void copy(int* f1, int* e1, int* f2)
{
	while (f1 != e1)
	{
		*(f2++) = *(f1++);
	}
}