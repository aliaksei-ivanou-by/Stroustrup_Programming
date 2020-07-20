#ifndef TASK_15_05_STDAFX_H
#include "Task_15_05_stdafx.h"
#endif

int main(int argc, char** argv)
try
{
	Simple_window win(Point(100, 100), xmax, ymax, "Leibniz");
	Axis x(Axis::x, Point(20, y_orig), xlength, xlength / x_scale, "one notch == 1");
	Axis y(Axis::y, Point(x_orig, ylength + 20), ylength, ylength / y_scale, "one notch == 1");
	win.attach(x);
	win.attach(y);
	x.set_color(Color::red);
	y.set_color(Color::red);

	Open_polyline figure;
	figure.add(Point(orig.x, orig.y - y_scale));
	win.attach(figure);
	win.wait_for_button();

	for (int i = 1; i <= 50; ++i)
	{
		ostringstream ss;
		ss << "Leibniz, element " << i;
		win.set_label(ss.str());
		int x = figure.point(i - 1).x + x_scale;
		int y = orig.y - leibniz(i) * y_scale;
		figure.add(Point(x, y));
		win.wait_for_button();
	}
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