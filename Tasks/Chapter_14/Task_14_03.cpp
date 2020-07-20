#ifndef TASK_14_03_STDAFX_H
#include "Task_14_03_stdafx.h"
#endif

int main(int argc, char** argv)
try
{
	Simple_window win(Point(100, 100), x_max() - 200, y_max() - 200, "Simple_window");
	AbstractClass a; // is protected constructor
	win.wait_for_button();
	return 0;
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