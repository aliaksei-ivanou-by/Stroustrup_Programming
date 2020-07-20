#include "Simple_window.h"
#include "Graph.h"

int main()
try
{
	using namespace Graph_lib;
	Point point(100, 100);
	Simple_window win(point, x_max() - 200, y_max() - 200, "My window");

	Line_style olymp_style(Line_style(Line_style::solid, 10));

	Circle c1(Point(200, 200), 100);
	c1.set_style(olymp_style);
	c1.set_color(Color::blue);
	win.attach(c1);

	Circle c2(Point(420, 200), 100);
	c2.set_style(olymp_style);
	c2.set_color(Color::black);
	win.attach(c2);

	Circle c3(Point(640, 200), 100);
	c3.set_style(olymp_style);
	c3.set_color(Color::red);
	win.attach(c3);

	Circle c4(Point(310, 330), 100);
	c4.set_style(olymp_style);
	c4.set_color(Color::yellow);
	win.attach(c4);

	Circle c5(Point(530, 330), 100);
	c5.set_style(olymp_style);
	c5.set_color(Color::green);
	win.attach(c5);

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