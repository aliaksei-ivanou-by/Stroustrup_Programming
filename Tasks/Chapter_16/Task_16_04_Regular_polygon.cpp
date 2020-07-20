#ifndef TASK_16_04_STDAFX_H
#include "Task_16_04_stdafx.h"
#include "Task_16_04_Regular_polygon.h"
#endif

Regular_polygon::Regular_polygon(Point cc, int nn, int dd)
	:c{ cc }, n{ nn }, d{ dd }
{
	if (n < 3)
	{
		error("The figure must have at least 3 sides");
	}
	add(Point(cc.x + dd, cc.y));
	for (int a = 360 / n; a < 360; a += 360 / n)
	{
		Point p((point(0).x - c.x) * cos(a * pi / 180) - (point(0).y - c.y) * sin(a * pi / 180) + c.x,
			(point(0).y - c.y) * cos(a * pi / 180) + (point(0).x - c.x) * sin(a * pi / 180) + c.y);
		add(p);
	}
}