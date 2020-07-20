#include "Simple_window.h"
#include "Graph.h"

int main()
try
{
	using namespace Graph_lib;
	Point point(100, 100);
	Simple_window win(point, 600, 400, "My window");

	Graph_lib::Rectangle rect(Point(300, 100), 100, 30);

	rect.set_color(Color::blue);

	win.attach(rect);

	Text t{ Point{325, 120}, "Howdy!" };

	win.attach(t);

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