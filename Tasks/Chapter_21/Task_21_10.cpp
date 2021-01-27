#ifndef TASK_21_10_STDAFX_H
#include "Task_21_10_stdafx.h"
#endif

int main(int argc, char** argv)
try
{
	std::vector<Order> orders;
	std::string fileName = "Task_21_10_File.txt";
	std::ifstream fileInputStream(fileName.c_str());
	if (!fileInputStream)
	{
		throw std::runtime_error("Can't open file " + fileName);
	}
	Order order;
	while (fileInputStream >> order)
	{
		orders.push_back(order);
		order = Order();
	}
	for (auto i = orders.begin(); i != orders.end(); ++i)
	{
		std::cout << *i;
	}
	double totalSum = 0;
	for (auto i = orders.begin(); i != orders.end(); ++i)
	{
		totalSum = std::inner_product(i->getClientPurchasesBegin(), i->getClientPurchasesEnd(),
			i->getClientPurchasesBegin(),
			totalSum,
			std::plus<double>(),
			[&orders](Purchase a, Purchase b) { return a.getPurchaseCount() * b.getPurchaseUnitPrice(); });
	}
	std::cout << "Total: " << totalSum << '\n';
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