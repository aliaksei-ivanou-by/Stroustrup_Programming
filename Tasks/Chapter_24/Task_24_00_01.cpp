#ifndef TASK_24_00_01_STDAFX_H
#include "Task_24_00_01_stdafx.h"
#endif

int main()
try
{
	float x = 1.0 / 10;
	float sum = 0;
	for (int i = 0; i < 10; ++i)
	{
		sum += x;
	}
	std::cout << std::setprecision(15) << sum << '\n';
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