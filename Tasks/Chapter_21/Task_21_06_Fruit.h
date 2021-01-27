#ifndef TASK_21_06_FRUIT_H
#define TASK_21_06_FRUIT_H

#ifndef TASK_21_06_STDAFX_H
#include "Task_21_06_stdafx.h"
#endif

struct Fruit
{
	std::string name;
	int count;
	double unit_price;
	Fruit(const std::string& n, const int c = 0, const double u_p = 0.0);
	friend std::ostream& operator<< (std::ostream& outputStream, const Fruit* fruit);
};

struct Fruit_comparison
{
	bool operator()(const Fruit* a, const Fruit* b) const;
};

#endif