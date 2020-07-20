#ifndef TASK_16_04_STDAFX_H
#include "Task_16_04_stdafx.h"
#endif

int main(int argc, char** argv)
try
{
	MyMenu win(Point(100, 100), x_max() - 200, y_max() - 200, "MyMenu");
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