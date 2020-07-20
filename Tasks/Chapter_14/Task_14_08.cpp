#ifndef TASK_14_08_STDAFX_H
#include "Task_14_08_stdafx.h"
#endif

int main(int argc, char** argv)
try
{
	Simple_window win(Point(100, 100), x_max() - 200, y_max() - 200, "Simple_window");
	Octagon figure(Point(200, 200), 100);
	figure.set_color(Color::red);
	figure.set_fill_color(Color::dark_magenta);
	figure.set_style(Line_style::dashdotdot);
	figure.move(300, 50);
	win.attach(figure);
	win.wait_for_button();
	std::cout << "Line color (int): " << figure.color().as_int() << '\n';
	std::cout << "Fill color (int): " << figure.fill_color().as_int() << '\n';
	std::cout << "Number of points: " << figure.number_of_points() << '\n';
	std::cout << "Points: \n";
	for (int i = 0; i < figure.number_of_points(); ++i)
	{
		std::cout << "Point " << i + 1 << ": " << figure.point(i).x << ", " << figure.point(i).y << '\n';
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