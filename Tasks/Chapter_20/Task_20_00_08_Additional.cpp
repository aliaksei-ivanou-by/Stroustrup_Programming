#ifndef TASK_20_00_08_STDAFX
#include "Task_20_00_08_stdafx.h"
#include "Task_20_00_08_Additional.h"
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