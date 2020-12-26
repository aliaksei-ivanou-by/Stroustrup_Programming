#ifndef TASK_21_06_STDAFX_H
#define TASK_21_06_STDAFX_H

#include <iostream>
#include <set>

#endif

struct Fruit
{
	std::string name;
	int count;
	double unit_price;
	Fruit(const std::string& n, int c = 0, double u_p = 0.0):
		name{ n },
		count{ c },
		unit_price{ u_p }
	{}
	friend std::ostream& operator<< (std::ostream& outputStream, const Fruit* fruit)
	{
		return outputStream
			<< fruit->name << '\t'
			<< fruit->count << '\t'
			<< fruit->unit_price;
	}
};

struct Fruit_comparison
{
	bool operator()(const Fruit* a, const Fruit* b) const
	{
		return a->name < b->name;
	}
};