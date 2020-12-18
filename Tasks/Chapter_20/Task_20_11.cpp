#ifndef TASK_20_11_STDAFX_H
#include "Task_20_11_stdafx.h"
#endif

int main()
try
{
	std::list<int> myList{ 9, 8, 7, 6, 5, 4, 3, 2, 10};
	std::vector<double> myVector = func(myList);
	std::sort(myVector.begin(), myVector.end());
	for (const auto& i : myVector)
	{
		std::cout << i << ' ';
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