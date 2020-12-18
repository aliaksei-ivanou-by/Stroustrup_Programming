#ifndef TASK_21_03_STDAFX_H
#include "Task_21_03_stdafx.h"
#endif

int main()
try
{
	std::vector<int> myVector = { 1, 2, 3, 4, 5, 6, 77, 54, 34, 2, 34, 4, 2, 23 };
	std::cout << "Number 2 in myVector (counts) : " <<
		myCount(myVector.begin(), myVector.end(), 2);
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