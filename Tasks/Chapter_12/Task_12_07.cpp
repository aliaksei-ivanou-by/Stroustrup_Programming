#include "Simple_window.h"
#include "Graph.h"

int main()
try
{
	using namespace Graph_lib;
	Point point(100, 100);
	Simple_window win(point, x_max() - 200, y_max() - 200, "My window");

	Line_style house_style(Line_style::solid,4);

	Graph_lib::Rectangle house(Point(100, 150), 500, 300);
	house.set_style(house_style);
	house.set_fill_color(Color::dark_red);
	win.attach(house);

	Graph_lib::Rectangle door(Point(310, 275), 80, 175);
	door.set_style(house_style);
	door.set_fill_color(Color::dark_green);
	win.attach(door);

	Graph_lib::Rectangle win1(Point(165, 275), 80, 80);
	win1.set_style(house_style);
	win1.set_fill_color(Color::cyan);
	win.attach(win1);

	Graph_lib::Rectangle win2(Point(455, 275), 80, 80);
	win2.set_style(house_style);
	win2.set_fill_color(Color::cyan);
	win.attach(win2);

	Graph_lib::Polygon roof;
	roof.add(Point(100, 150));
	roof.add(Point(350, 50));
	roof.add(Point(600, 150));
	roof.set_style(house_style);
	roof.set_fill_color(Color::dark_blue);
	win.attach(roof);

	Graph_lib::Polygon chimney;
	chimney.add(Point(400, 70));
	chimney.add(Point(450, 90));
	chimney.add(Point(450, 50));
	chimney.add(Point(400, 50));
	chimney.set_style(house_style);
	chimney.set_fill_color(Color::dark_magenta);
	win.attach(chimney);

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