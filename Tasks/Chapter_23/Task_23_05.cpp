#ifndef TASK_23_05_STDAFX_H
#include "Task_23_05_stdafx.h"
#endif

int main()
try
{
	testMap();
	testUnorderedMap();
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