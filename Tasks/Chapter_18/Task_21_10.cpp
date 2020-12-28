#ifndef TASK_21_10_STDAFX_H
#include "Task_21_10_stdafx.h"
#endif

int main()
try
{
	std::vector<Order> orders;
	std::string fileNameFrom("Task_21_10_fileNameFrom.txt");
	std::ifstream inputStream(fileNameFrom.c_str());
	if (!inputStream)
	{
		throw ("Can't open file");
	}
	Order order;
	while (inputStream >> order)
	{
		orders.push_back(order);
		order = Order();
	}
	for (auto i = orders.begin(); i != orders.end(); ++i)
	{
		std::cout << *i;
	}
	inputStream.close();

	double totalSum = 0.0;
	for (auto i = orders.begin(); i != orders.end(); ++i)
	{
		totalSum = std::inner_product(i->get_clientPurchasesBegin(), i->get_clientPurchasesEnd(),
			i->get_clientPurchasesBegin(),
			totalSum,
			std::plus<double>(),
			[&i](const Purchase& a, const Purchase& b) { return a.get_count() * b.get_unit_price(); });
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