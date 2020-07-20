#ifndef TASK_14_05_STDAFX_H
#include "Task_14_05_stdafx.h"
#include "Task_14_05_Striped_rectangle.h"
#endif

Striped_rectangle::Striped_rectangle(Point p, int rec_w, int rec_h)
	: Rectangle{ p, rec_w, rec_h }
{
	for (int i = p.y + 2; i < p.y + rec_h; i += 2)
	{
		lines.add(Point(p.x, i), Point(p.x + rec_w - 1, i));
		lines.set_color(Color::black);
	}
}

void Striped_rectangle::draw_lines() const
{
	lines.draw();
	Rectangle::draw_lines();
}
