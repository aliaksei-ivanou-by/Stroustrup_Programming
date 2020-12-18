#ifndef TASK_20_11_STDAFX_H
#define TASK_20_11_STDAFX_H

#include <iostream>
#include <list>
#include <vector>
#include <algorithm>

#endif

std::vector<double> func(const std::list<int>& myList)
{
	std::vector<double> myVector(myList.size());
	std::copy(myList.begin(), myList.end(), myVector.begin());
	if (myList.size() != myVector.size())
	{
		throw ("myList size != myVector size");
	}
	return myVector;
}