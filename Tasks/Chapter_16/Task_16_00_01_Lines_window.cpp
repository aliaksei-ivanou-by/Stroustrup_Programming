#ifndef TASK_16_00_01_STDAFX_H
#include "Task_16_00_01_stdafx.h"
#include "Task_16_00_01_Lines_window.h"
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
	color_menu{ Point(x_max() - 100, 40), 70, 20, Menu::vertical, "color" },
	cmenu_button{ Point(x_max() - 100, 30), 80, 20, "color_menu", cb_cmenu },
	style_menu{ Point(x_max() - 200, 40), 70, 20, Menu::vertical, "style" },
	smenu_button{ Point(x_max() - 200, 30), 80, 20, "style_menu", cb_smenu }
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
	attach(cmenu_button);
	style_menu.attach(new Button(Point(0, 0), 0, 0, "solid", cb_solid));
	style_menu.attach(new Button(Point(0, 0), 0, 0, "dot", cb_dot));
	style_menu.attach(new Button(Point(0, 0), 0, 0, "dash", cb_dash));
	attach(style_menu);
	style_menu.hide();
	attach(smenu_button);
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

void Graph_lib::Lines_window::cb_cmenu(Address, Address pw)
{
	reference_to<Lines_window>(pw).cmenu_pressed();
}

void Graph_lib::Lines_window::cb_solid(Address, Address pw)
{
	reference_to<Lines_window>(pw).solid_pressed();
}

void Graph_lib::Lines_window::cb_dot(Address, Address pw)
{
	reference_to<Lines_window>(pw).dot_pressed();
}

void Graph_lib::Lines_window::cb_dash(Address, Address pw)
{
	reference_to<Lines_window>(pw).dash_pressed();
}

void Graph_lib::Lines_window::cb_smenu(Address, Address pw)
{
	reference_to<Lines_window>(pw).smenu_pressed();
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
	hide_cmenu();
}

void Graph_lib::Lines_window::blue_pressed()
{
	change(Color::blue);
	hide_cmenu();
}

void Graph_lib::Lines_window::black_pressed()
{
	change(Color::black);
	hide_cmenu();
}

void Graph_lib::Lines_window::solid_pressed()
{
	change_style(Line_style(Line_style::solid));
	hide_smenu();
}

void Graph_lib::Lines_window::dot_pressed()
{
	change_style(Line_style(Line_style::dot));
	hide_smenu();
}

void Graph_lib::Lines_window::dash_pressed()
{
	change_style(Line_style(Line_style::dash));
	hide_smenu();
}

void Graph_lib::Lines_window::smenu_pressed()
{
	smenu_button.hide();
	style_menu.show();
}

void Graph_lib::Lines_window::cmenu_pressed()
{
	cmenu_button.hide();
	color_menu.show();
}

void Graph_lib::Lines_window::change(Color c)
{
	lines.set_color(c);
}

void Graph_lib::Lines_window::change_style(Line_style ls)
{
	lines.set_style(ls);
}

void Graph_lib::Lines_window::hide_cmenu()
{
	color_menu.hide();
	cmenu_button.show();
}

void Graph_lib::Lines_window::hide_smenu()
{
	style_menu.hide();
	smenu_button.show();
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
