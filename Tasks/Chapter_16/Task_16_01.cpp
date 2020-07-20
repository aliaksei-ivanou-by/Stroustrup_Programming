#ifndef TASK_16_01_STDAFX_H
#include "Task_16_01_stdafx.h"
#endif

int main(int argc, char** argv)
try
{
	My_window win(Point(100, 100), x_max() - 200, y_max() - 200, "Simple_window");
	Graph_lib::Rectangle r(Point(150, 150), 200, 100);
	win.attach(r);
	win.wait_for_button();
	r.move(200, 200);
	win.wait_for_button();
	r.move(-200, -200);
	win.wait_for_button();
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