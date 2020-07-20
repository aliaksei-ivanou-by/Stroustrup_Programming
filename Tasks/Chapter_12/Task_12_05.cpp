#include "Simple_window.h"
#include "Graph.h"

int main()
try
{
	using namespace Graph_lib;
	Point point(100, 100);
	Simple_window win(point, x_max() - 100, y_max() - 100, "My window");

	Graph_lib::Rectangle rect(Point(15, 15), x_max() * 2 / 3, y_max() * 3 / 4);
	rect.set_color(Color::red);
	rect.set_style(Line_style(Line_style::solid, 19));
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