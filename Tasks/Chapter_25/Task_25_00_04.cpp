#ifndef TASK_25_00_04_STDAFX_H
#include "Task_25_00_04_stdafx.h"
#endif

int main()
try
{
	infinite();
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