#ifndef TASK_21_06_STDAFX_H
#include "Task_21_06_stdafx.h"
#endif

int main()
try
{
	std::set<Fruit*, Fruit_comparison> inventory;
	inventory.insert(std::make_unique<Fruit>("quince", 5).release());
	inventory.insert(std::make_unique<Fruit>("apple", 200, 0.37).release());
	for (const auto& i : inventory)
	{
		std::cout << i << '\n';
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