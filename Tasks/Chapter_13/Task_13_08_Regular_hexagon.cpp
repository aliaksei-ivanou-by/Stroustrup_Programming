#include "Task_13_08_Regular_hexagon.h"

Regular_hexagon::Regular_hexagon(Point cc, int dd)
	:c{ cc }, d{ dd }
{
	add(Point(cc.x + dd, cc.y));
	for (int a = 360 / n; a < 360; a += 360 / n)
	{
		Point p((point(0).x - c.x) * cos(a * pi / 180) - (point(0).y - c.y) * sin(a * pi / 180) + c.x,
			(point(0).y - c.y) * cos(a * pi / 180) + (point(0).x - c.x) * sin(a * pi / 180) + c.y);
		add(p);
	}
}