#ifndef TASK_14_06_STDAFX_H
#include "Task_14_06_stdafx.h"
#include "Task_14_06_Striped_circle.h"
#endif

Striped_circle::Striped_circle(Point p, int r)
	: Circle{ p, r }
{
	for (int i = p.y - r; i < p.y + r; i += 2)
	{
		int temp = sqrt(pow(r, 2) - pow(p.y - i, 2));
		lines.add(Point(p.x - temp, i), Point(p.x + temp, i));
		lines.set_color(Color::black);
	}
}

void Striped_circle::draw_lines() const
{
	lines.draw();
	Circle::draw_lines();
}
