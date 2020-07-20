#ifndef TASK_14_07_STDAFX_H
#include "Task_14_07_stdafx.h"
#endif

int main(int argc, char** argv)
try
{
	Simple_window win(Point(100, 100), x_max() - 200, y_max() - 200, "Simple_window");
	Graph_lib::Striped_closed_polyline figure(2);
	figure.add(Point(100, 100));
	figure.add(Point(150, 200));
	figure.add(Point(250, 250));
	figure.add(Point(300, 200));
	figure.set_color(Color::black);
	win.attach(figure);
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