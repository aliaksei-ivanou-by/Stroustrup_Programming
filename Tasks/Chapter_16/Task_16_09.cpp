#ifndef TASK_16_09_STDAFX_H
#include "Task_16_09_stdafx.h"
#endif

int main(int argc, char** argv)
try
{
	Graph_lib::Calculator_window win(Point(100, 100), 400, 150, "Calculator");
	return gui_main();
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