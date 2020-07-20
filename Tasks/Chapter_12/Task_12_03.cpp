#include "Simple_window.h"
#include "Graph.h"

int main()
try
{
	using namespace Graph_lib;
	Point point(100, 100);
	Simple_window win(point, 600, 400, "My window");

	Open_polyline letter_a;
	letter_a.add(Point(100, 200));
	letter_a.add(Point(150, 50));
	letter_a.add(Point(125, 125));
	letter_a.add(Point(175, 125));
	letter_a.add(Point(150, 50));
	letter_a.add(Point(200, 200));

	letter_a.set_color(Color::blue);
	letter_a.set_style(Line_style(Line_style::solid, 4));
	win.attach(letter_a);

	Open_polyline letter_i;
	letter_i.add(Point(300, 200));
	letter_i.add(Point(300, 50));

	letter_i.set_color(Color::red);
	letter_i.set_style(Line_style(Line_style::solid, 4));
	win.attach(letter_i);

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