#include "Task_13_08_Regular_hexagon.h"

int main()
try
{
	Simple_window win(Point(100, 100), x_max() - 200, y_max() - 200, "Simple_window");
	Regular_hexagon r_h(Point(200, 200), 100);
	r_h.set_color(Color::black);
	win.attach(r_h);
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