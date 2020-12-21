#ifndef TASK_20_16_STDAFX_H
#include "Task_20_16_stdafx.h"
#endif

int main()
try
{
	ovector<int> oVector;
	for (int i = 0; i < 10; ++i)
	{
		oVector.push_back(new int(i));
	}
	for (auto i = 0; i < oVector.size(); ++i)
	{
		std::cout << oVector[i] << '\n';
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