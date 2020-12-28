#ifndef TASK_21_09_STDAFX_H
#include "Task_21_09_stdafx.h"
#endif

int main()
try
{
	// FILE 1
	std::vector<Order> orders1;
	std::string fileNameFrom1("Task_21_09_fileNameFrom1.txt");
	std::string fileNameTo1("Task_21_09_fileNameTo1.txt");
	std::ifstream inputStream1(fileNameFrom1.c_str());
	if (!inputStream1)
	{
		throw ("Can't open file");
	}
	Order order1;
	while (inputStream1 >> order1)
	{
		orders1.push_back(order1);
		order1 = Order();
	}
	std::cout << "\n\nOriginal list from FIRST FILE: \n";
	for (auto i = orders1.begin(); i != orders1.end(); ++i)
	{
		std::cout << *i;
	}
	std::sort(orders1.begin(), orders1.end());
	std::cout << "\n\nSorted list from FIRST FILE by client name: \n";
	for (auto i = orders1.begin(); i != orders1.end(); ++i)
	{
		std::cout << *i;
	}
	inputStream1.close();
	std::ofstream outputStream1(fileNameTo1.c_str(), std::ios_base::trunc);
	for (auto i = orders1.begin(); i != orders1.end(); ++i)
	{
		outputStream1 << *i;
	}
	outputStream1.close();

	// FILE 2
	std::list<Order> orders2;
	std::string fileNameFrom2("Task_21_09_fileNameFrom2.txt");
	std::string fileNameTo2("Task_21_09_fileNameTo2.txt");
	std::ifstream inputStream2(fileNameFrom2.c_str());
	if (!inputStream2)
	{
		throw ("Can't open file");
	}
	Order order2;
	while (inputStream2 >> order2)
	{
		orders2.push_back(order2);
		order2 = Order();
	}
	std::cout << "\n\nOriginal list from SECOND FILE: \n";
	for (auto i = orders2.begin(); i != orders2.end(); ++i)
	{
		std::cout << *i;
	}
	orders2.sort([&](Order& a, Order& b) { return a.get_clientAddress() < b.get_clientAddress(); });
	std::cout << "\n\nSorted list from SECOND FILE by client address: \n";
	for (auto i = orders2.begin(); i != orders2.end(); ++i)
	{
		std::cout << *i;
	}
	inputStream2.close();
	std::ofstream outputStream2(fileNameTo2.c_str(), std::ios_base::trunc);
	for (auto i = orders2.begin(); i != orders2.end(); ++i)
	{
		outputStream2 << *i;
	}
	outputStream2.close();

	// FILE 3
	std::string fileNameTo3("Task_21_09_fileNameTo3.txt");
	std::ofstream outputStream3(fileNameTo3.c_str());
	std::vector<Order> orders3(orders2.begin(), orders2.end());
	std::sort(orders3.begin(), orders3.end());
	std::vector<Order> all(orders1.size() + orders3.size());
	std::merge(orders1.begin(), orders1.end(), orders3.begin(), orders3.end(), all.begin());
	std::set<Order> mySet;
	for (const auto& i : all)
	{
		mySet.insert(i);
	}
	std::cout << "\n\nMERGED list from FIRST FILE and SECOND FILE: \n";
	for (auto i : mySet)
	{
		std::cout << i;
	}
	for (auto i : mySet)
	{
		outputStream3 << i;
	}
	outputStream3.close();
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