#include "Simple_window.h"
#include "Graph.h"

int main()
try
{
	Point point(100, 100);
	Simple_window win(point, x_max() - 200, y_max() - 200, "My window");

	Graph_lib::Polygon triangle;
	triangle.add(Point(200, 100));
	triangle.add(Point(300, 100));
	triangle.add(Point(250, 186));
	win.attach(triangle);

	Open_polyline square;
	square.add(Point(200, 100));
	square.add(Point(200, 200));
	square.add(Point(300, 200));
	square.add(Point(300, 100));
	win.attach(square);

	Open_polyline pentagon;
	pentagon.add(Point(200, 100));
	pentagon.add(Point(169, 195));
	pentagon.add(Point(250, 259));
	pentagon.add(Point(331, 195));
	pentagon.add(Point(300, 100));
	win.attach(pentagon);

	Open_polyline hexagon;
	hexagon.add(Point(200, 100));
	hexagon.add(Point(150, 187));
	hexagon.add(Point(200, 274));
	hexagon.add(Point(300, 274));
	hexagon.add(Point(350, 187));
	hexagon.add(Point(300, 100));
	win.attach(hexagon);

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