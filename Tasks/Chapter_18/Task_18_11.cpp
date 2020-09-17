#ifndef TASK_18_11_STDAFX_H
#include "Task_18_11_stdafx.h"
#endif

int main()
try
{
	srand(static_cast<int>(time(NULL)));
	Skip_List list;
	std::cout << "Enter size of List: ";
	int n = 0;
	std::cin >> n;
	for (int i = 0; i < n; ++i)
	{
		list.insert(i);
		//list.insert(rand() % 100);
	}
	std::cout << "1. New List:\n";
	list.print();
	std::cout << "2. Remove element:\n";
	list.remove(5);
	list.print();
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