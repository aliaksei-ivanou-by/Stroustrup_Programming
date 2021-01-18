#ifndef TASK_24_07_STDAFX_H
#include "Task_24_07_stdafx.h"
#endif

int main()
try
{
	solve_random_system_classical(3);
	solve_random_system_classical(4);
	solve_random_system_classical(5);
	
	solve_random_system_pivotal(3);
	solve_random_system_pivotal(4);
	solve_random_system_pivotal(5);
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