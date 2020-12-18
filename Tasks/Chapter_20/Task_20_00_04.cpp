#ifndef TASK_20_00_04_STDAFX_H
#include "Task_20_00_04_stdafx.h"
#endif

int main()
try
{
	fct();
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