#ifndef TASK_14_08_OCTAGON_H
#include "Task_14_08_stdafx.h"
#include "Task_14_08_Octagon.h"
#endif

Octagon::Octagon(Point cc, int dd)
	:cen{ cc }, d{ dd }
{
	add(Point(cc.x + dd, cc.y));
	for (int a = 360 / n; a < 360; a += 360 / n)
	{
		Point p((point(0).x - cen.x) * cos(a * pi / 180) - (point(0).y - cen.y) * sin(a * pi / 180) + cen.x,
			(point(0).y - cen.y) * cos(a * pi / 180) + (point(0).x - cen.x) * sin(a * pi / 180) + cen.y);
		add(p);
	}
}
