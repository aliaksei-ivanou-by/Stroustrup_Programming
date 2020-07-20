#ifndef TASK_14_01_STDAFX_H
#include "Task_14_01_stdafx.h"
#endif

Frowny::Frowny(Point p, int rr)
	: Circle(p, rr),
	eye_L(Point(p.x - rr / 5, p.y - rr / 2), rr / 10, rr / 5),
	eye_R(Point(p.x + rr / 5, p.y - rr / 2), rr / 10, rr / 5),
	mouth(p, rr / 2, rr / 2, 0, 180)
{
	eye_L.set_color(Color::dark_red);
	eye_L.set_fill_color(Color::red);
	eye_R.set_color(Color::dark_red);
	eye_R.set_fill_color(Color::red);
	mouth.set_color(Color::dark_red);
}

void Frowny::draw_lines() const
{
	Circle::draw_lines();
	eye_L.draw();
	eye_R.draw();
	mouth.draw();
}
