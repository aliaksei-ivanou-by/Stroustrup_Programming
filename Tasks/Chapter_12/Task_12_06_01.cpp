#include "Simple_window.h"
#include "Graph.h"

int main()
try
{
	using namespace Graph_lib;
	Point point(100, 100);
	Simple_window win(point, x_max() - 200, y_max() - 200, "My window");

	Graph_lib::Rectangle rect(Point(100, 100), x_max() - 100, y_max() - 100);
	win.attach(rect);
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