#include "Simple_window.h"
#include "Graph.h"

int main()
try
{
	using namespace Graph_lib;
	Point t1(100, 100);
	Simple_window win(t1, 600, 400, "Canvas");
	win.wait_for_button();
	Axis xa(Axis::x, Point(20, 300), 280, 10, "x axis");
	win.attach(xa);
	win.set_label("Canvas #2");
	win.wait_for_button();
	Axis ya(Axis::y, Point(20, 300), 280, 10, "y axis");
	ya.set_color(Color::cyan);
	ya.label.set_color(Color::dark_red);
	win.attach(ya);
	win.set_label("Canvas #3");
	win.wait_for_button();
	Function sin(sin, 0, 100, Point(20, 150), 1000, 50, 50);
	win.attach(sin);
	win.set_label("Canvas #4");
	win.wait_for_button();
	sin.set_color(Color::blue);
	Graph_lib::Polygon poly;
	poly.add(Point(300, 200));
	poly.add(Point(350, 100));
	poly.add(Point(400, 200));
	poly.set_color(Color::red);
	poly.set_style(Line_style::dash);
	win.attach(poly);
	win.set_label("Canvas #5");
	win.wait_for_button();
	Graph_lib::Rectangle r(Point(200, 200), 100, 50);
	win.attach(r);
	win.set_label("Canvas #6");
	win.wait_for_button();
	Closed_polyline poly_rect;
	poly_rect.add(Point(100, 50));
	poly_rect.add(Point(200, 50));
	poly_rect.add(Point(200, 100));
	poly_rect.add(Point(100, 100));
	poly_rect.add(Point(50, 75));
	win.attach(poly_rect);
	win.set_label("Canvas #6-1");
	win.wait_for_button();
	r.set_fill_color(Color::yellow);
	poly.set_style(Line_style(Line_style::dash, 4));
	poly_rect.set_style(Line_style(Line_style::dash, 2));
	poly_rect.set_fill_color(Color::green);
	win.set_label("Canvas #7");
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