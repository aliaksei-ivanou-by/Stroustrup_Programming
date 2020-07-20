#include "Task_13_19_Star.h"

int main()
try
{
	Simple_window win(Point(100, 100), x_max() - 200, y_max() - 200, "Simple_window");
	Star star1(Point(400, 300), 4, 40);
	Star star2(Point(800, 300), 5, 40);
	star1.set_fill_color(Color::blue);
	win.attach(star1);
	star2.set_fill_color(Color::red);
	star2.set_color(Color::black);
	win.attach(star2);
	win.wait_for_button();
}
catch (const exception& e)
{
	std::cout << "Exception occured: " << e.what() << '\n';
	return 1;
}
catch (...)
{
	return 2;
}