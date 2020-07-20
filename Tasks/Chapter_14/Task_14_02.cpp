#ifndef TASK_14_02_STDAFX_H
#include "Task_14_02_stdafx.h"
#endif

int main(int argc, char** argv)
try
{
	Simple_window win(Point(100, 100), x_max() - 200, y_max() - 200, "Simple_window");
	Graph_lib::Circle figure1(Point(200, 200), 50);
	win.attach(figure1);
	win.wait_for_button();
	Graph_lib::Circle figure2(figure1); // is deleted copy constructor
	win.attach(figure2);
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