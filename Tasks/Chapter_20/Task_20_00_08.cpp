#ifndef TASK_20_00_08_STDAFX_H
#include "Task_20_00_08_stdafx.h"
#endif

int main()
try
{
	int myInt[] = { 1, 2, 3, 4, 5 };
	funInt(myInt, sizeof(myInt) / sizeof(myInt[0]));
	std::cout << '\n';

	std::vector<int> myVector = { 1, 2, 3, 4, 5 };
	funVector(myVector);
	std::cout << '\n';

	std::list<int> myList = { 1, 2, 3, 4, 5 };
	funcList(myList);
	std::cout << '\n';
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