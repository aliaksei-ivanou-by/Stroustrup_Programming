#ifndef TASK_14_17_STDAFX_H
#include "Task_14_17_stdafx.h"
#include "Task_14_17_Box.h"
#endif

Box::Box(Point p, int ww, int hh)
	:w{ ww }, h{ hh }
{
	add(p);
	double wp = (double(w) / 100) * 10;
	double hp = (double(h) / 100) * 10;
	// Top
	add(Point(p.x + wp, p.y));
	add(Point((p.x + w) - wp, p.y));
	// Right
	add(Point(p.x + w, p.y + hp));
	add(Point(p.x + w, (p.y + h) - hp));
	// Bottom
	add(Point(p.x + wp, p.y + h));
	add(Point((p.x + w) - wp, p.y + h));
	// Left
	add(Point(p.x, p.y + hp));
	add(Point(p.x, (p.y + h) - hp));
}

void Box::draw_lines() const
{
	for (int i = 2; i < number_of_points(); i += 2)
	{
		fl_line(point(i - 1).x, point(i - 1).y, point(i).x, point(i).y);
	}
	double we = ((double(w) / 100) * 10) * 2;
	double he = ((double(h) / 100) * 10) * 2;
	fl_arc(point(0).x, point(0).y, we, he, 90, 180);
	fl_arc((point(0).x + w) - we, point(0).y, we, he, 0, 90);
	fl_arc((point(0).x + w) - we, (point(0).y + h) - he, we, he, 270, 360);
	fl_arc(point(0).x, (point(0).y + h) - he, we, he, 180, 270);
}