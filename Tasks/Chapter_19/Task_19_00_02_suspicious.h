#ifndef TASK_19_00_02_SUSPICIOUS_H
#define TASK_19_00_02_SUSPICIOUS_H

#ifndef TASK_19_00_02_STDAFX_H
#include "Task_19_00_02_stdafx.h"
#endif

void suspicious(std::vector<int>& v, int s)
{
	int* p = nullptr;
	int* q = nullptr;
	try
	{
		int* p = new int[s];
	}
	catch (...)
	{
		delete[] p;
		throw;
	}
	std::vector<int> v1;
	try
	{
		int* q = new int[s];
	}
	catch (...)
	{
		delete[] p;
		delete[] q;
		throw;
	}
	std::vector<double> v2;
	delete[] p;
	delete[] q;
}

#endif