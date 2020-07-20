#include "Task_13_01_Arc.h"

int main()
try
{
	Simple_window win(Point(100, 100), x_max() - 100, y_max() - 100, "Simple_window");
	Graph_lib::Arc arc1(Point(200, 200), 50, 50, 0, 360);
	Graph_lib::Arc arc2(Point(200, 200), 100, 50, 90, 360);
	Graph_lib::Arc arc3(Point(200, 200), 100, 150, 90, 360);
	win.attach(arc1);
	win.attach(arc2);
	win.attach(arc3);
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