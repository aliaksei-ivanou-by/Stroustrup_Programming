#ifndef TASK_14_01_STDAFX_H
#include "Task_14_01_stdafx.h"
#endif

Frowny_Hat::Frowny_Hat(Point p, int rr)
	: Frowny(p, rr)
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

void Frowny_Hat::draw_lines() const
{
	Frowny::draw_lines();
	hat.draw_lines();
}
