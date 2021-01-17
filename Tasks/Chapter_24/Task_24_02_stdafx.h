#ifndef TASK_24_02_STDAFX_H
#define TASK_24_02_STDAFX_H

#include <iostream>
#include "Matrix.h"
#include "MatrixIO.h"

#endif

struct TripleRef // Modifies input parameter
{
	void operator()(int& n)
	{
		n *= 3;
	}
};

struct TripleInt // Doesn't modify input parameter
{
	int operator()(int n)
	{
		return n * 3;
	}
};

struct TripleIntRef // Modifies input parameter
{
	int operator()(int& n)
	{
		return n *= 3;
	}
};