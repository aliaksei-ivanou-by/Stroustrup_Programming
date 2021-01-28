#ifndef TASK_24_01_STDAFX_H
#include "Task_24_01_stdafx.h"
#include "Task_24_01_func.h"
#endif

void tripleRef(int& n)
{
	n *= 3;
}

int tripleInt(int n)
{
	return n * 3;
}

int tripleIntRef(int& n)
{
	return n *= 3;
}