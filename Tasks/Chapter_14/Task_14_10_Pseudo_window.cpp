#ifndef TASK_14_10_STDAFX_H
#include "Task_14_10_stdafx.h"
#include "Task_14_10_Pseudo_window.h"
#endif

Pseudo_window::Pseudo_window(Point pp, int ww, int hh, std::string ss, std::string imgimg)
	: p{ pp }, w{ ww }, h{ hh }, 
	s{ Point(p.x + w * 0.4, p.y + w * 0.04), ss },
	window{ p, w, h },
	close{ Point(p.x + w * 0.1, p.y + h * 0.05), (w + h) / 2 * 0.02 },
	maximize{ Point(p.x + w * 0.15, p.y + h * 0.05), (w + h) / 2 * 0.02 },
	minimize{ Point(p.x + w * 0.2, p.y + h * 0.05), (w + h) / 2 * 0.02 },
	img{ window.point(7), imgimg },
	l{ Point(p.x, window.point(7).y), Point(p.x + w, window.point(7).y) }
{
	img.set_mask(Point(0, 0), w, window.point(6).y - 140);
	s.set_font_size(15);
	s.set_font(Font::courier_bold);
	s.set_color(Color::black);
	window.set_color(Color::black);
	window.set_fill_color(Color::white);
	close.set_color(Color::dark_red);
	close.set_fill_color(Color::dark_red);
	maximize.set_color(Color::red);
	maximize.set_fill_color(Color::red);
	minimize.set_color(Color::green);
	minimize.set_fill_color(Color::green);
	l.set_color(Color::black);
}

void Graph_lib::Pseudo_window::draw_lines() const
{
	window.draw();
	s.draw();
	minimize.draw();
	maximize.draw();
	close.draw();
	img.draw();
	l.draw();
}
