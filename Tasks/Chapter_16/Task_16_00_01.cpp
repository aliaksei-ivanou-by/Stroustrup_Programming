#ifndef TASK_16_00_01_STDAFX_H
#include "Task_16_00_01_stdafx.h"
#endif

int main(int argc, char** argv)
try
{
	Graph_lib::Lines_window win(Point(100, 100), 600, 400, "lines");
	return Graph_lib::gui_main();
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