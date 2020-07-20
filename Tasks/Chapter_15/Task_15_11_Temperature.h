#ifndef TASK_15_11_DISTRIBUTION_H
#define TASK_15_11_DISTRIBUTION_H

#ifndef TASK_15_11_STDAFX_H
#include "Task_15_11_stdafx.h"
#endif

struct Temperature
{
public:
	int month;
	double t1;
	double t2;
};

istream& operator>>(istream& is, Temperature& t);

#endif