#ifndef TASK_20_11_STDAFX
#include "Task_20_11_stdafx.h"
#include "Task_20_11_Additional.h"
#endif

std::vector<double> func(const std::list<int>& myList)
{
	std::vector<double> myVector(myList.size());
	std::copy(myList.begin(), myList.end(), myVector.begin());
	if (myList.size() != myVector.size())
	{
		throw std::runtime_error("myList size != myVector size");
	}
	return myVector;
}