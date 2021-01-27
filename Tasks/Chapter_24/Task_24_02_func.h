#ifndef TASK_24_02_FUNC_H
#define TASK_24_02_FUNC_H

#ifndef TASK_24_02_STDAFX_H
#include "Task_24_02_stdafx.h"
#endif

struct TripleRef // Modifies input parameter
{
	void operator()(int& n);
};

struct TripleInt // Doesn't modify input parameter
{
	int operator()(int n);
};

struct TripleIntRef // Modifies input parameter
{
	int operator()(int& n);
};

#endif