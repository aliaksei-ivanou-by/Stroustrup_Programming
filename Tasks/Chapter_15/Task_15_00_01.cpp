#ifndef TASK_15_00_01_STDAFX_H
#include "Task_15_00_01_stdafx.h"
#endif

int main(int argc, char** argv)
try
{
	// 1.1
	Simple_window win(Point(100, 100), xmax, ymax, "Function graphs");
	// 1.4
	Axis x(Axis::x, Point(100, y_orig), xlength, xlength / x_scale, "1 == 20 pixels");
	x.label.move(-160, 0);
	Axis y(Axis::y, Point(x_orig, 500), ylength, ylength / y_scale, "1 == 20 pixels");
	// 1.5
	x.set_color(Color::red);
	y.set_color(Color::red);
	win.attach(x);
	win.attach(y);
	win.wait_for_button();
	// 2.1
	Function one1(one, r_min, r_max, orig, n_points);
	win.attach(one1);
	win.wait_for_button();
	// 2.2
	Function one2(one, r_min, r_max, orig, n_points, x_scale, y_scale);
	win.attach(one2);
	win.wait_for_button();
	// 2.4
	Function slope1(slope, r_min, r_max, orig, n_points, x_scale, y_scale);
	win.attach(slope1);
	win.wait_for_button();
	// 2.5
	Text slope1_label(Point(100, y_orig + 4 * y_scale), "x / 2");
	win.attach(slope1_label);
	win.wait_for_button();
	// 2.6
	Function square1(square, r_min, r_max, orig, n_points, x_scale, y_scale);
	win.attach(square1);
	win.wait_for_button();
	// 2.7
	Function cos1(cos, r_min, r_max, orig, n_points, x_scale, y_scale);
	win.attach(cos1);
	win.wait_for_button();
	// 2.8
	cos1.set_color(Color::blue);
	win.wait_for_button();
	// 2.9
	Function sloping_cos1(sloping_cos, r_min, r_max, orig, n_points, x_scale, y_scale);
	win.attach(sloping_cos1);
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