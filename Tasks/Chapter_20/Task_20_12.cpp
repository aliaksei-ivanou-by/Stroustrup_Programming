#ifndef TASK_20_12_STDAFX_H
#include "Task_20_12_stdafx.h"
#endif

int main()
try
{
	list<int> myList;
	int number;
	while (std::cin >> number)
	{
		myList.push_back(number);
	}
	auto p = high(myList.begin(), myList.end());
	std::cout << "High value of myList is " << *p << '\n';
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