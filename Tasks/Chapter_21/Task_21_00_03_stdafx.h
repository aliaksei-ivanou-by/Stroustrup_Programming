#ifndef TASK_21_00_03_STDAFX_H
#define TASK_21_00_03_STDAFX_H

#include <iostream>
#include <vector>
#include <numeric>

#endif

class Record
{
public:
	double unit_price;
	int units;
	Record(double up, int u) :
		unit_price{ up },
		units{ u }
	{}
};

double price(double v, const Record& r)
{
	return v + r.unit_price * r.units;
}

void f(const std::vector<Record>& vr)
{
	double total = accumulate(vr.begin(), vr.end(), 0.0, price);
	std::cout << "Total number is " << total << '\n';
}