#ifndef BOOK_16_01_STDAFX_H
#include "Book_16_01_stdafx.h"
#include "Book_16_01_Lines_window.h"
#endif

Graph_lib::Lines_window::Lines_window(Point xy, int w, int h, const std::string& title)
	: Window{ xy, w, h, title }, 
	next_button{ Point(x_max() - 150, 0), 70, 20, "Next point", 
				[](Address, Address pw) {reference_to<Lines_window>(pw).next(); } }, 
	quit_button{ Point(x_max() - 70, 0), 70, 20, "Quit", 
				[](Address, Address pw) {reference_to<Lines_window>(pw).quit(); } }, 
	next_x{ Point(x_max() - 310, 0), 50, 20, "next_x:" }, 
	next_y{ Point(x_max() - 210, 0), 50, 20, "next_y:" }, 
	xy_out{ Point(100, 0), 100, 20, "current (x, y):" }
{
	attach(next_button);
	attach(quit_button);
	attach(next_x);
	attach(next_y);
	attach(xy_out);
	attach(lines);
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
