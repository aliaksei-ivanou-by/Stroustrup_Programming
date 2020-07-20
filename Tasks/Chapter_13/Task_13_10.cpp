#include "Task_13_10_Regular_polygon.h"

int main()
try
{
	Simple_window win(Point(100, 100), x_max() - 200, y_max() - 200, "Simple_window");
	Regular_polygon r_p(Point(200, 200), 8, 100);
	r_p.set_color(Color::black);
	win.attach(r_p);
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