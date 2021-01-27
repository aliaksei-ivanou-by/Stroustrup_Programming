#ifndef TASK_25_00_02_STDAFX_H
#include "Task_25_00_02_stdafx.h"
#endif

int main()
try
{
	Graph_lib::Shape* q = new Graph_lib::Rectangle{ Point{ 0, 0 }, Point{ 10, 20 } };
	std::vector<Graph_lib::Circle> s0;
	f(q, s0);
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