#ifndef TASK_20_15_STDAFX_H
#include "Task_20_15_stdafx.h"
#endif

int main()
try
{
	pvector<int> pVector;
	for (int i = 0; i < 10; ++i)
	{
		pVector.push_back(new int(i));
	}
	for (auto i = 0; i < pVector.size(); ++i)
	{
		std::cout << *pVector[i] << '\n';
	}
	return 0;
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