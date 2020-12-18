#ifndef TASK_25_05_STDAFX_H
#include "Task_25_05_stdafx.h"
#endif

int main()
try
{
	while (true)
	{
		std::cout << "Hello, World!\n";
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