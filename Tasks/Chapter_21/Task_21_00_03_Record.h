#ifndef TASK_21_00_03_RECORD_H
#define TASK_21_00_03_RECORD_H

#ifndef TASK_21_00_03_STDAFX_H
#include "Task_21_00_03_stdafx.h"
#endif

class Record
{
public:
	double unit_price;
	int units;
	Record(double up, int u);
};

double price(double v, const Record& r);
void f(const std::vector<Record>& vr);

#endif