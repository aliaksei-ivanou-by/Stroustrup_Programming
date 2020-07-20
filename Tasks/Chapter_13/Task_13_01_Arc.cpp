#include "Task_13_01_Arc.h"

Arc::Arc(Point center, int width, int height, double start, double end)
	:width{ width }, height{ height }, start{ start }, end{ end }
{
	add(center);
}

void Arc::draw_lines() const
{
	if (color().visibility())
	{
		fl_arc(point(0).x - width / 2, point(0).y, width, height, start, end);
	}
}