#ifndef TASK_20_12_STDAFX_H
#include "Task_20_12_stdafx.h"
#endif

int main()
try
{
	my_list<int> list1;
	std::cout << " 0 elements list size: " << list1.size() << '\n';
	my_list<int> list2(10);
	std::cout << "10 elements list size: " << list2.size() << '\n';

	my_list<int> list3;
	list3.push_front(1);
	list3.push_front(2);
	list3.push_front(3);
	list3.push_back(4);
	list3.push_back(5);
	list3.push_back(6);
	for (auto& i : list3)
	{
		std::cout << i << ' ';
	}
	std::cout << '\n';
	auto iterator = list3.begin();
	++iterator;
	list3.insert(iterator, 55);
	for (auto& i : list3)
	{
		std::cout << i << ' ';
	}
	std::cout << '\n';

	my_list<int> listHigh;
	int number;
	while (std::cin >> number)
	{
		listHigh.push_back(number);
	}
	auto p = high(listHigh.begin(), listHigh.end());
	std::cout << "High value of listHigh is " << *p << '\n';
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