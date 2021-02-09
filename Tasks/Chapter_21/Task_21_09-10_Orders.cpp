#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <list>
#include <set>
#include <numeric>
#include "Task_21_09-10-11-12_Order.h"

int main(int argc, char** argv)
try
{
	// FILE 1
	std::vector<Order> orders1;
	std::string fileName1 = "Task_21_09-10_File1.txt";
	std::string fileName1Result = "Task_21_09-10_File1_result.txt";
	std::ifstream fileInputStream1(fileName1);
	if (!fileInputStream1)
	{
		throw std::runtime_error("Can't open file" + fileName1);
	}
	Order order1;
	while (fileInputStream1 >> order1)
	{
		orders1.push_back(order1);
		order1 = Order();
	}
	std::cout << "\nList from FILE 1 - ORIGINAL\n\n";
	for (auto i = orders1.begin(); i != orders1.end(); ++i)
	{
		std::cout << *i;
	}
	std::sort(orders1.begin(), orders1.end());
	std::cout << "\nList from FILE 1 - SORT BY NAME\n\n";
	for (auto i = orders1.begin(); i != orders1.end(); ++i)
	{
		std::cout << *i;
	}
	fileInputStream1.close();

	std::ofstream fileOutputStream1(fileName1Result.c_str(), std::ios_base::trunc);
	for (auto i = orders1.begin(); i != orders1.end(); ++i)
	{
		fileOutputStream1 << *i;
	}
	fileOutputStream1.close();

	// FILE 2
	std::list<Order> orders2;
	std::string fileName2 = "Task_21_09-10_File2.txt";
	std::string fileName2Result = "Task_21_09-10_File2_result.txt";
	std::ifstream fileInputStream2(fileName2);
	if (!fileInputStream2)
	{
		throw std::runtime_error("Can't open file" + fileName2);
	}
	Order order2;
	while (fileInputStream2 >> order2)
	{
		orders2.push_back(order2);
		order2 = Order();
	}
	std::cout << "\nList from FILE 2 - ORIGINAL\n\n";
	for (auto i = orders2.begin(); i != orders2.end(); ++i)
	{
		std::cout << *i;
	}
	orders2.sort([&orders2](const Order& a, const Order& b) { return a.getClientAddress() < b.getClientAddress(); });
	std::cout << "\nList from FILE 2 - SORT BY ADDRESS\n\n";
	for (auto i = orders2.begin(); i != orders2.end(); ++i)
	{
		std::cout << *i;
	}
	fileInputStream2.close();

	std::ofstream fileOutputStream2(fileName2Result.c_str(), std::ios_base::trunc);
	for (auto i = orders2.begin(); i != orders2.end(); ++i)
	{
		fileOutputStream2 << *i;
	}
	fileOutputStream2.close();

	// FILE 3
	std::string fileName3Result = "Task_21_09-10_File3_result.txt";
	std::ofstream fileOutputStream3(fileName3Result);
	std::vector<Order> orders2Vector(orders2.begin(), orders2.end());
	std::sort(orders2Vector.begin(), orders2Vector.end());
	std::vector<Order> ordersMerge(orders1.size() + orders2.size());
	std::merge(orders1.begin(), orders1.end(), orders2Vector.begin(), orders2Vector.end(), ordersMerge.begin());
	std::cout << "\nList from FILE 1 and FILE 2 - SORT BY NAME\n\n";
	for (auto i = ordersMerge.begin(); i != ordersMerge.end(); ++i)
	{
		std::cout << *i;
	}
	for (auto i = ordersMerge.begin(); i != ordersMerge.end(); ++i)
	{
		fileOutputStream3 << *i;
	}
	fileOutputStream3.close();

	// FILE 4
	std::set<Order> mySet;
	std::string fileName4Result = "Task_21_09-10_File4_result.txt";
	std::ofstream fileOutputStream4(fileName4Result);
	for (auto i = ordersMerge.begin(); i != ordersMerge.end(); ++i)
	{
		mySet.insert(*i);
	}
	for (auto i = mySet.begin(); i != mySet.end(); ++i)
	{
		fileOutputStream4 << *i;
	}
	fileOutputStream4.close();

	// Sum of ordersMerge
	double totalSum = 0;
	for (auto i = ordersMerge.begin(); i != ordersMerge.end(); ++i)
	{
		totalSum = std::inner_product(i->getClientPurchasesBegin(), i->getClientPurchasesEnd(),
			i->getClientPurchasesBegin(),
			totalSum,
			std::plus<double>(),
			[&ordersMerge](Purchase a, Purchase b) { return a.getPurchaseCount() * b.getPurchaseUnitPrice(); });
	}
	std::cout << "Total sum of ordersMerge: " << totalSum << '\n';
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