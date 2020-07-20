#ifndef TASK_14_17_STDAFX_H
#include "Task_14_17_stdafx.h"
#include "Task_14_17_Box_text.h"
#endif

Box_text::Box_text(Point p, string ss)
	: Rectangle(p, ss.length() * 6, 40), text(Point(p.x + 5, p.y + 30), ss)
{
	add(p);
	text.set_font_size(10);
}

void Box_text::draw_lines() const
{
	Rectangle::draw_lines();
	text.draw_lines();
}