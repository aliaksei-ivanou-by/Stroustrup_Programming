#ifndef BOOK_16_02_STDAFX_H
#include "Book_16_02_stdafx.h"
#include "Book_16_02_Lines_window.h"
#endif

Graph_lib::Lines_window::Lines_window(Point xy, int w, int h, const std::string& title)
	: Window{ xy, w, h, title }, 
	next_button{ Point(x_max() - 150, 0), 70, 20, "Next point", 
				[](Address, Address pw) {reference_to<Lines_window>(pw).next(); } }, 
	quit_button{ Point(x_max() - 70, 0), 70, 20, "Quit", 
				[](Address, Address pw) {reference_to<Lines_window>(pw).quit(); } }, 
	next_x{ Point(x_max() - 310, 0), 50, 20, "next_x:" }, 
	next_y{ Point(x_max() - 210, 0), 50, 20, "next_y:" }, 
	xy_out{ Point(100, 0), 100, 20, "current (x, y):" }, 
	color_menu{ Point(x_max() - 70, 40), 70, 20, Menu::vertical, "color" }, 
	menu_button{ Point(x_max() - 80, 30), 80, 20, "color_menu", cb_menu }
{
	attach(next_button);
	attach(quit_button);
	attach(next_x);
	attach(next_y);
	attach(xy_out);
	xy_out.put("no point");
	color_menu.attach(new Button(Point(0, 0), 0, 0, "red", cb_red));
	color_menu.attach(new Button(Point(0, 0), 0, 0, "blue", cb_blue));
	color_menu.attach(new Button(Point(0, 0), 0, 0, "black", cb_black));
	attach(color_menu);
	color_menu.hide();
	attach(menu_button);
	attach(lines);
}

void Graph_lib::Lines_window::cb_red(Address, Address pw)
{
	reference_to<Lines_window>(pw).red_pressed();
}

void Graph_lib::Lines_window::cb_blue(Address, Address pw)
{
	reference_to<Lines_window>(pw).blue_pressed();
}

void Graph_lib::Lines_window::cb_black(Address, Address pw)
{
	reference_to<Lines_window>(pw).black_pressed();
}

void Graph_lib::Lines_window::cb_menu(Address, Address pw)
{
	reference_to<Lines_window>(pw).menu_pressed();
}

void Graph_lib::Lines_window::cb_next(Address, Address pw)
{
	reference_to<Lines_window>(pw).next();
}

void Graph_lib::Lines_window::cb_quit(Address, Address pw)
{
	reference_to<Lines_window>(pw).quit();
}

void Graph_lib::Lines_window::red_pressed()
{
	change(Color::red);
	hide_menu();
}

void Graph_lib::Lines_window::blue_pressed()
{
	change(Color::blue);
	hide_menu();
}

void Graph_lib::Lines_window::black_pressed()
{
	change(Color::black);
	hide_menu();
}

void Graph_lib::Lines_window::menu_pressed()
{
	menu_button.hide();
	color_menu.show();
}

void Graph_lib::Lines_window::change(Color c)
{
	lines.set_color(c);
}

void Graph_lib::Lines_window::hide_menu()
{
	color_menu.hide();
	menu_button.show();
}

void Graph_lib::Lines_window::next()
{
	int x = next_x.get_int();
	int y = next_y.get_int();
	lines.add(Point(x, y));
	ostringstream ss;
	ss << '(' << x << ',' << y << ')';
	xy_out.put(ss.str());
	redraw();
}

void Graph_lib::Lines_window::quit()
{
	hide();
}
