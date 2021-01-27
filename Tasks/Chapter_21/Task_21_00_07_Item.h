#ifndef TASK_21_00_07_ITEM_H
#define TASK_21_00_07_ITEM_H

#ifndef TASK_21_00_07_STDAFX_H
#include "Task_21_00_07_stdafx.h"
#endif

struct Item
{
	std::string name;
	int iid;
	double value;
	Item();
	Item(const std::string& n, const int i, const double v);
	friend std::istream& operator>>(std::istream& inputStream, Item& i);
	friend std::ostream& operator<<(std::ostream& outputStream, const Item& i);
};

template<typename In>
void print(In first, In last)
{
	while (first != last)
	{
		std::cout << *first << '\n';
		++first;
	}
	std::cout << '\n';
}

template<class T1, class T2>
std::ostream& operator<<(std::ostream& outputStream, const std::pair<T1, T2>& p)
{
	outputStream << std::setw(12) << p.first << '\t' << p.second;
	return outputStream;
}

void get_map(std::map<std::string, int>& myMap);
void part11();
void part12();
void part2();
void part3();

#endif