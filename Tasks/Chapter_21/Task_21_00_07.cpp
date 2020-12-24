#ifndef TASK_21_00_07_STDAFX_H
#include "Task_21_00_07_stdafx.h"
#endif

int main()
try
{
	//part11(); // 1.1 - 7 vector
	//part12(); // 1.8 list
	//part2(); // 2 map
	part3(); // 3 vector
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