#include "Simple_window.h"
#include "Graph.h"

int main()
try
{
	using namespace Graph_lib;
	Point point(100, 100);
	Simple_window win(point, 600, 400, "My window");

	Graph_lib::Rectangle rect(Point(100, 100), 100, 50);

	Graph_lib::Polygon poly;
	poly.add(Point(250, 100));
	poly.add(Point(350, 100));
	poly.add(Point(350, 150));
	poly.add(Point(250, 150));

	rect.set_color(Color::blue);
	poly.set_color(Color::red);

	win.attach(rect);

	win.attach(poly);

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