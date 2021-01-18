#ifndef TASK_25_08_STDAFX_H
#include "Task_25_08_stdafx.h"
#endif

int main()
try
{
	for (int i = 32; i <= 126; ++i)
	{
		std::cout << i << '\t' << char(i) << '\n';
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