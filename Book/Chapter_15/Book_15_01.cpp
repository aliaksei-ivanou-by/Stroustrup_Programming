#ifndef BOOK_15_01_STDAFX_H
#include "Book_15_01_stdafx.h"
#endif

int main(int argc, char** argv)
try
{
	Simple_window win(Point(100, 100), xmax, ymax, "Simple_window");
	
	Function s1(one, r_min, r_max, orig, n_points, x_scale, y_scale);
	Function s2(slope, r_min, r_max, orig, n_points, x_scale, y_scale);
	Function s3(square, r_min, r_max, orig, n_points, x_scale, y_scale);
	win.attach(s1);
	win.attach(s2);
	win.attach(s3);
	win.wait_for_button();

	Text ts1(Point(100, y_orig - 40), "one");
	Text ts2(Point(100, y_orig + y_orig / 2 - 20), "x/2");
	Text ts3(Point(x_orig - 100, 20), "x*x");
	win.attach(ts1);
	win.attach(ts2);
	win.attach(ts3);
	win.set_label("Functional graphing: label functions");
	win.wait_for_button();

	Axis x(Axis::x, Point(20, y_orig), xlength, xlength / x_scale, "one notch == 1");
	Axis y(Axis::y, Point(x_orig, ylength + 20), ylength, ylength / y_scale, "one notch == 1");
	x.set_color(Color::red);
	y.set_color(Color::red);
	win.attach(x);
	win.attach(y);
	win.wait_for_button();

	Function s4(cos, r_min, r_max, orig, 400, 30, 30);
	s4.set_color(Color::blue);
	Function s5(sloping_cos, r_min, r_max, orig, 400, 30, 30);
	x.label.move(-160, 0);
	x.notches.set_color(Color::dark_red);
	win.attach(s4);
	win.attach(s5);
	win.wait_for_button();

	Function f1(log, 0.000001, r_max, orig, 200, 30, 30);
	Function f2(sin, r_min, r_max, orig, 200, 30, 30);
	f2.set_color(Color::blue);
	Function f3(cos, r_min, r_max, orig, 200, 30, 30);
	Function f4(exp, r_min, r_max, orig, 200, 30, 30);
	win.attach(f1);
	win.attach(f2);
	win.attach(f3);
	win.attach(f4);
	win.wait_for_button();

	Function s6([](double x) -> double { return cos(x) + slope(x); }, 
		r_min, r_max, orig, 400, 30, 30);
	s6.set_color(Color::red);
	win.attach(s6);
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