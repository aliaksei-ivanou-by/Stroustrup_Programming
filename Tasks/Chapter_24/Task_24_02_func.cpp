#ifndef TASK_24_02_STDAFX
#include "Task_24_02_stdafx.h"
#include "Task_24_02_func.h"
#endif

void TripleRef::operator()(int& n)
{
	n *= 3;
}

int TripleInt::operator()(int n)
{
	return n * 3;
}

int TripleIntRef::operator()(int& n)
{
	return n *= 3;
}
