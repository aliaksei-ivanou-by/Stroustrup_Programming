#ifndef TASK_20_14_STDAFX_H
#include "Task_20_14_stdafx.h"
#endif

int main()
try
{
	slist<int> myList;
	int number;
	while (std::cin >> number)
	{
		myList.push_front(number);
	}
	auto p = high(myList.begin(), myList.end());
	std::cout << "High value of myList is " << *p;
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