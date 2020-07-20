#include "Task_13_09_Regular_hexagon.h"

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

Graph_lib::Vector_ref<Regular_hexagon> hexagons(Point c, int d, int n_y, int n_x)
{
	Graph_lib::Vector_ref<Regular_hexagon> r;
	for (int i = 0; i < n_y; i++)
	{
		if (i == 0)
		{
			r.push_back(new Regular_hexagon(c, d));
		}
		else
		{
			if (!(i % 2))
			{
				r.push_back(new Regular_hexagon(Point(r[r.size() - n_x].point(1).x + d,
					r[r.size() - n_x].point(1).y),
					d));
			}
			else
			{
				if (i % 2)
				{
					r.push_back(new Regular_hexagon(Point(r[r.size() - n_x].point(1).x - d * 2,
						r[r.size() - n_x].point(1).y),
						d));
				}
			}
		}
		for (int a = 0; a < n_x - 1; a++)
		{
			r.push_back(new Regular_hexagon(Point(r[r.size() - 1].point(5).x + d,
				r[r.size() - 1].point(5).y),
				d));
		}
	}
	return r;
}