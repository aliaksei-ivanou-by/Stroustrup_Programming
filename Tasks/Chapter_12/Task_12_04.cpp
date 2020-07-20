#include "Simple_window.h"
#include "Graph.h"

int main()
try
{
	using namespace Graph_lib;
	Point point(100, 100);
	Simple_window win(point, 600, 400, "My window");

	// 1 line

	Graph_lib::Rectangle rect11(Point(100, 50), 100, 100);
	rect11.set_fill_color(Color::white);
	win.attach(rect11);

	Graph_lib::Rectangle rect12(Point(200, 50), 100, 100);
	rect12.set_fill_color(Color::red);
	win.attach(rect12);

	Graph_lib::Rectangle rect13(Point(300, 50), 100, 100);
	rect13.set_fill_color(Color::white);
	win.attach(rect13);

	// 2 line

	Graph_lib::Rectangle rect21(Point(100, 150), 100, 100);
	rect21.set_fill_color(Color::red);
	win.attach(rect21);

	Graph_lib::Rectangle rect22(Point(200, 150), 100, 100);
	rect22.set_fill_color(Color::white);
	win.attach(rect22);

	Graph_lib::Rectangle rect23(Point(300, 150), 100, 100);
	rect23.set_fill_color(Color::red);
	win.attach(rect23);

	// 3 line

	Graph_lib::Rectangle rect31(Point(100, 250), 100, 100);
	rect31.set_fill_color(Color::white);
	win.attach(rect31);

	Graph_lib::Rectangle rect32(Point(200, 250), 100, 100);
	rect32.set_fill_color(Color::red);
	win.attach(rect32);

	Graph_lib::Rectangle rect33(Point(300, 250), 100, 100);
	rect33.set_fill_color(Color::white);
	win.attach(rect33);

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