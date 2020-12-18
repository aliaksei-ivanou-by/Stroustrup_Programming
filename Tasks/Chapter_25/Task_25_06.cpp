#ifndef TASK_25_06_STDAFX_H
#include "Task_25_06_stdafx.h"
#endif

int main()
try
{
	for (char i = 0; i < 128; ++i)
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