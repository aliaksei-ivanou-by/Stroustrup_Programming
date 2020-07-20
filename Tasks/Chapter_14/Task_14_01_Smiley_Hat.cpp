#ifndef TASK_14_01_STDAFX_H
#include "Task_14_01_stdafx.h"
#endif

Smiley_Hat::Smiley_Hat(Point p, int rr)
	: Smiley(p, rr)
{
	hat.add(Point(p.x - 0.7 * rr, p.y - 0.7 * rr));
	hat.add(Point(p.x - 0.8 * rr, p.y - 0.9 * rr));
	hat.add(Point(p.x - 0.6 * rr, p.y - 0.9 * rr));
	hat.add(Point(p.x - 0.6 * rr, p.y - 1.9 * rr));
	hat.add(Point(p.x + 0.6 * rr, p.y - 1.9 * rr));
	hat.add(Point(p.x + 0.6 * rr, p.y - 0.9 * rr));
	hat.add(Point(p.x + 0.8 * rr, p.y - 0.9 * rr));
	hat.add(Point(p.x + 0.7 * rr, p.y - 0.7 * rr));
	hat.set_fill_color(Color::dark_magenta);
}

void Smiley_Hat::draw_lines() const
{
	Smiley::draw_lines();
	hat.draw_lines();
}
