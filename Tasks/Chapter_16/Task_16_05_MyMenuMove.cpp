#ifndef TASK_16_05_STDAFX_H
#include "Task_16_05_stdafx.h"
#include "Task_16_05_MyMenuMove.h"
#endif

Graph_lib::My_window::My_window(Point xy, int w, int h, const string& title)
	: Window{ xy, w, h, title },
	quit_button{ Point(x_max() - 70, 30), 70, 20, "Quit", cb_quit }
{
	attach(quit_button);
}

void Graph_lib::My_window::cb_quit(Address, Address pw)
{
	reference_to<My_window>(pw).quit();
}

void Graph_lib::My_window::quit()
{
	hide();
}

Graph_lib::MyMenu::MyMenu(Point xy, int w, int h, const string& title)
	: My_window{ xy, w, h, title },
	mymenu{ Point(x_max() - 70, 70), 70, 30, Menu::vertical, "figures" },
	clear_btn{ Point(x_max() - 70, 260), 70, 30, "Clear", cb_clear },
	x_pos{ Point(x_max() - 70, 200), 70, 30, "x: " },
	y_pos{ Point(x_max() - 70, 230), 70, 30, "y: " },
	x{ 0 },
	y{ 0 }
{
	mymenu.attach(new Button(Point(0, 0), 0, 0, "Circle", cb_circle));
	mymenu.attach(new Button(Point(0, 0), 0, 0, "Square", cb_square));
	mymenu.attach(new Button(Point(0, 0), 0, 0, "Triangle", cb_triangle));
	mymenu.attach(new Button(Point(0, 0), 0, 0, "Hexagon", cb_hexagon));
	attach(mymenu);
	attach(x_pos);
	attach(y_pos);
	attach(clear_btn);
}

void Graph_lib::MyMenu::get_position()
{
	x = x_pos.get_int();
	y = y_pos.get_int();
}

void Graph_lib::MyMenu::draw_circle()
{
	get_position();
	figures.push_back(new Circle(Point(x, y), 150));
	attach(figures[figures.size() - 1]);
	redraw();
}

void Graph_lib::MyMenu::draw_square()
{
	get_position();
	figures.push_back(new Rectangle(Point(x - 150, y - 150), 300, 300));
	attach(figures[figures.size() - 1]);
	redraw();
}

void Graph_lib::MyMenu::draw_triangle()
{
	get_position();
	figures.push_back(new Regular_polygon(Point(x, y), 3, 150));
	attach(figures[figures.size() - 1]);
	redraw();
}

void Graph_lib::MyMenu::draw_hexagon()
{
	get_position();
	figures.push_back(new Regular_polygon(Point(x, y), 6, 150));
	attach(figures[figures.size() - 1]);
	redraw();
}

void Graph_lib::MyMenu::cb_circle(Address, Address pw)
{
	reference_to<MyMenu>(pw).draw_circle();
}

void Graph_lib::MyMenu::cb_square(Address, Address pw)
{
	reference_to<MyMenu>(pw).draw_square();
}

void Graph_lib::MyMenu::cb_triangle(Address, Address pw)
{
	reference_to<MyMenu>(pw).draw_triangle();
}

void Graph_lib::MyMenu::cb_hexagon(Address, Address pw)
{
	reference_to<MyMenu>(pw).draw_hexagon();
}

void Graph_lib::MyMenu::cb_clear(Address, Address pw)
{
	reference_to<MyMenu>(pw).clear();
}

void Graph_lib::MyMenu::clear()
{
	for (int i = 0; i < figures.size(); ++i)
	{
		detach(figures[figures.size() - i - 1]);
	}
	redraw();
}

Graph_lib::MyMenuMove::MyMenuMove(Point xy, int w, int h, const string& title)
	: MyMenu{ xy, w, h, title }, 
	next_btn{ Point(x_max() - 70, 0), 70, 20, "Next", cb_move }
{
	attach(next_btn);
}

void Graph_lib::MyMenuMove::next()
{
	if (figures.size() == 0)
	{
		error("No figures");
	}
	int x_old = x;
	int y_old = y;
	///////////////
	// 1
	std::cout << "Enter new coordinates (x y): \n";
	std::cin >> x >> y;
	///////////////
	// 2
	//get_position();
	///////////////
	int dx = x - x_old;
	int dy = y - y_old;
	figures[figures.size() - 1].move(dx, dy);
	redraw();
}

void Graph_lib::MyMenuMove::cb_move(Address, Address pw)
{
	reference_to<MyMenuMove>(pw).next();
}

