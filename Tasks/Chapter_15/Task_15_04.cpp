#ifndef TASK_15_04_STDAFX_H
#include "Task_15_04_stdafx.h"
#endif

int main(int argc, char** argv)
try
{
	Simple_window win(Point(100, 100), xmax, ymax, "Simple_window");
	Axis x(Axis::x, Point(20, y_orig), xlength, xlength / x_scale, "one notch == 1");
	x.label.move(-x_orig / 2, 0);
	Axis y(Axis::y, Point(x_orig, ylength + 20), ylength, ylength / y_scale, "one notch == 1");
	win.attach(x);
	win.attach(y);
	x.set_color(Color::white);
	y.set_color(Color::white);
	win.wait_for_button();

	// sin, black
	Function f_sin(sin, r_min, r_max, orig, n_points, x_scale, y_scale);
	f_sin.set_color(Color::black);
	win.attach(f_sin);
	Text f_sin_label(Point(50, 50), "sin");
	f_sin_label.set_color(Color::black);
	win.attach(f_sin_label);
	win.wait_for_button();

	// cos, dark_red
	Function f_cos(cos, r_min, r_max, orig, n_points, x_scale, y_scale);
	f_cos.set_color(Color::dark_red);
	win.attach(f_cos);
	Text f_cos_label(Point(50, 70), "cos");
	f_cos_label.set_color(Color::dark_red);
	win.attach(f_cos_label);
	win.wait_for_button();

	// sin + cos, dark_blue
	Function sum_sc(sum_sin_cos, r_min, r_max, orig, n_points, x_scale, y_scale);
	sum_sc.set_color(Color::dark_blue);
	win.attach(sum_sc);
	Text sum_sc_label(Point(50, 90), "sin + cos");
	sum_sc_label.set_color(Color::dark_blue);
	win.attach(sum_sc_label);
	win.wait_for_button();

	// sin * sin + cos * cos, dark_green
	Function sum_sq_sc(sum_sq_sin_cos, r_min, r_max, orig, n_points, x_scale, y_scale);
	sum_sq_sc.set_color(Color::dark_green);
	win.attach(sum_sq_sc);
	Text sum_sq_sc_label(Point(50, 110), "sin * sin + cos * cos");
	sum_sq_sc_label.set_color(Color::dark_green);
	win.attach(sum_sq_sc_label);
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