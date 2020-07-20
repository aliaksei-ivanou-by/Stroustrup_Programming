#ifndef TASK_15_03_STDAFX_H
#include "Task_15_03_stdafx.h"
#endif

double one(double)
{
	return 1;
}

double slope(double x)
{
	return x / 2;
}

double square(double x)
{
	return x * x;
}

double sloping_cos(double x)
{
	return cos(x) + slope(x);
}

int main(int argc, char** argv)
try
{
	Simple_window win(Point(100, 100), xmax, ymax, "Simple_window");
	Axis x(Axis::x, Point(100, y_orig), xlength, xlength / x_scale, "1 == 20 pixels");
	x.label.move(-160, 0);
	Axis y(Axis::y, Point(x_orig, 500), ylength, ylength / y_scale, "1 == 20 pixels");
	x.set_color(Color::red);
	y.set_color(Color::red);
	win.attach(x);
	win.attach(y);
	win.wait_for_button();

	MyFunction s(one, r_min, r_max, Point(x_orig, y_orig), n_points, x_scale - 10, y_scale - 10);
	win.attach(s);
	win.wait_for_button();

	s.set_x_scale(x_scale);
	s.set_y_scale(y_scale);
	win.wait_for_button();

	s.set_func(sin);
	win.wait_for_button();

	s.set_n_points(15);
	win.wait_for_button();

	s.set_orig(Point(x_orig + 50, y_orig + 50));
	win.wait_for_button();

	s.set_range(-5, 5);
	win.wait_for_button();

	s.set_orig(Point(x_orig, y_orig));
	s.set_range(r_min, r_max);
	s.set_n_points(n_points);
	win.wait_for_button();

	s.set_precision(8);
	win.wait_for_button();

	s.set_precision(1);
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