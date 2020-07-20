#ifndef TASK_14_14_ARROW_H
#include "Task_14_14_stdafx.h"
#include "Task_14_14_Arrow.h"
#endif

Arrow::Arrow(Point tail, Point tip)
{
	add(tail);
	add(tip);
}

Arrow::Arrow(Point tail, Point tip, Color line_color)
{
	add(tail);
	add(tip);
	set_color(line_color);
}

void Arrow::draw_lines() const
{
	int diff_x = point(1).x - point(0).x;
	int diff_y = point(1).y - point(0).y;
	double angle = atan2(diff_y, diff_x) * 180 / pi;
	double x1 = point(1).x - cos((angle - delta) * pi / 180) * size;
	double y1 = point(1).y - sin((angle - delta) * pi / 180) * size;
	double x2 = point(1).x - cos((angle + delta) * pi / 180) * size;
	double y2 = point(1).y - sin((angle + delta) * pi / 180) * size;
	Graph_lib::Polygon head;
	head.add(point(1));
	head.add(Point(int(x1), int(y1)));
	head.add(Point(int(x2), int(y2)));
	head.set_fill_color(color());
	head.draw_lines();
	Shape::draw_lines();
}
