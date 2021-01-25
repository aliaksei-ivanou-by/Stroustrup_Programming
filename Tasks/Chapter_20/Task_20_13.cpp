#ifndef TASK_20_13_STDAFX_H
#include "Task_20_13_stdafx.h"
#endif

int main()
try
{
	my_list<int> list1;
	std::cout << "sizeof(list):\t" << sizeof(list1) << '\n';
	my_list<int>* list2;
	std::cout << "sizeof(list*):\t" << sizeof(list2) << '\n';

	my_list<int> list3;
	list3.push_front(1);
	list3.push_front(2);
	list3.push_front(3);
	list3.push_back(4);
	list3.push_back(5);
	list3.push_back(6);
	for (auto i = list3.begin(); i != list3.end(); ++i)
	{
		std::cout << *i << ' ';
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