#ifndef TASK_21_06_STDAFX
#include "Task_21_06_stdafx.h"
#include "Task_21_06_Fruit.h"
#endif

Fruit::Fruit(const std::string& n, const int c, const double u_p):
	name{ n },
	count{ c },
	unit_price{ u_p }
{}

std::ostream& operator<<(std::ostream& outputStream, const Fruit* fruit)
{
	return outputStream
		<< fruit->name << '\t'
		<< fruit->count << '\t'
		<< fruit->unit_price;
}

bool Fruit_comparison::operator()(const Fruit* a, const Fruit* b) const
{
	return a->name < b->name;
}
