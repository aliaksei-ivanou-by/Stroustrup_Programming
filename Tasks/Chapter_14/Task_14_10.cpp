#ifndef TASK_14_10_STDAFX_H
#include "Task_14_10_stdafx.h"
#endif

int main(int argc, char** argv)
try
{
	Simple_window win(Point(100, 100), x_max() - 200, y_max() - 200, "Simple_window");
	Graph_lib::Pseudo_window ps_win(Point(100, 100), 400, 200, "Pseudo_window", "c:/git_data/Stroustrup_Programming/pics/image.jpg");
	win.attach(ps_win);
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