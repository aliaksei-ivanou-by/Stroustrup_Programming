#include "Task_13_19_Star.h"

Star::Star(Point cc, int nn, int rr)
	:c{ cc }, n{ nn }, r{ rr }
{
	add(Point(c.x, c.y - r));
	add(find_distance(
		Point((point(0).x - c.x)* cos((r* pi / 180)) - (point(0).y - c.y) * sin((r * pi / 180)) + c.x,
			(point(0).y - c.y)* cos((r* pi / 180)) + (point(0).x - c.x) * sin((r * pi / 180)) + c.y),
		c, r));
	for (int a = 360 / n; a < 360; a += 360 / n)
	{
		add(Point((point(0).x - c.x) * cos((a * pi / 180)) - (point(0).y - c.y) * sin((a * pi / 180)) + c.x,
			(point(0).y - c.y) * cos((a * pi / 180)) + (point(0).x - c.x) * sin((a * pi / 180)) + c.y));
		Point rp((point(number_of_points() - 1).x - c.x) * cos((180 / n * pi / 180)) - (point(number_of_points() - 1).y - c.y) * sin((180 / n * pi / 180)) + c.x,
			(point(number_of_points() - 1).y - c.y) * cos((180 / n * pi / 180)) + (point(number_of_points() - 1).x - c.x) * sin((180 / n * pi / 180)) + c.y);
		add(find_distance(rp, c, r));
	}
}

Point Star::find_distance(Point p1, Point p2, int d)
{
	double dx = p1.x - p2.x;
	double dy = p1.y - p2.y;
	double delta = sqrt(dx * dx + dy * dy);
	return Point(int(double(p1.x) + (dx / delta) * (delta + double(d))),
		int(double(p1.y) + (dy / delta) * (delta + double(d))));
}