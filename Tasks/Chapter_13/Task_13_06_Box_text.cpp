#include "Task_13_06_Box_text.h"

Box_text::Box_text(Point p, string ss)
	: Rectangle(p, ss.length() * 10, 40), text(Point(p.x + 5, p.y + 30), ss)
{
	add(p);
}

void Box_text::draw_lines() const
{
	Rectangle::draw_lines();
	text.draw_lines();
}