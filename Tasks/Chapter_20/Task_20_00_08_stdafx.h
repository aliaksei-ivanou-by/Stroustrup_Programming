#ifndef TASK_20_00_08_STDAFX_H
#define TASK_20_00_08_STDAFX_H

#include <iostream>
#include <vector>
#include <list>

#endif

void funInt(const int myInt[], const int size)
{
	std::cout << "funInt\n";
	std::cout << size << " is myInt size\n";
}

void funVector(const std::vector<int>& myVector)
{
	std::cout << "funVector\n";
	std::cout << myVector.size() << " is myVector size\n";
}

void funcList(const std::list<int>& myList)
{
	std::cout << "funcList\n";
	std::cout << myList.size() << " is myList size\n";
}