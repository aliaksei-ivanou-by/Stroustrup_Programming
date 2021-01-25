#ifndef TASK_20_19_STDAFX_H
#include "Task_20_19_stdafx.h"
#endif

int main()
try
{
	my_list<int> myList;
	int n = 10;
	for (int i = n; i > 0; --i)
	{
		myList.push_front(i);
	}
	for (int i = n; i > 0; --i)
	{
		myList.push_back(i);
	}

	std::cout << '\n';
	for (auto i : myList)
	{
		std::cout << i << ' ';
	}
	std::cout << '\n';

	try
	{
		auto myIterator = myList.begin();
		--myIterator;
	}
	catch (std::out_of_range&)
	{
		std::cout << "Decrement from begin.\tError - Out of range\n";
	}

	try
	{
		auto myIterator = myList.end();
		++myIterator;
	}
	catch (std::out_of_range&)
	{
		std::cout << "Decrement from end.\tError - Out of range\n";
	}
}
catch (const std::exception& e)
{
	std::cout << "Exception occured: " << e.what() << '\n';
	return 1;
}
catch (...)
{
	return 2;
}