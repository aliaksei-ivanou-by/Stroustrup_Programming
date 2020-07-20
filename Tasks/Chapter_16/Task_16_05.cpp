#ifndef TASK_16_05_STDAFX_H
#include "Task_16_05_stdafx.h"
#endif

int main(int argc, char** argv)
try
{
	MyMenuMove win(Point(100, 100), x_max() - 200, y_max() - 200, "MyMenuMove");
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