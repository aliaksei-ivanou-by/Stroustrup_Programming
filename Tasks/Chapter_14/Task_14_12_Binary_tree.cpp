#ifndef TASK_14_12_BINARY_TREE_H
#include "Task_14_12_stdafx.h"
#include "Task_14_12_Binary_tree.h"
#endif

Binary_tree::Binary_tree(Point pp, int ll, int rr)
	:l{ ll }, r{ rr }
{
	if (l == 0)
	{
		error("The minimum level value must be greater than zero.");
	}
	int dx = 40 * r;
	int dy = dx / 10;
	for (int i = 0; i < l; ++i)
	{
		if (i == 0)
		{
			add(pp);
		}
		else
		{
			dx /= 2;
			vector<Point> points;
			for (int j = pow(2, i - 1) - 1; j < pow(2, i) - 1; ++j)
			{
				points.push_back(Point(point(j).x - dx, point(j).y + dy));
				points.push_back(Point(point(j).x + dx, point(j).y + dy));
			}
			for (Point s : points)
			{
				add(s);
			}
		}
	}
	for (int i = 0; i < number_of_points(); ++i)
	{
		if (i < pow(2, l - 1) - 1)
		{
			v_lines.push_back(new Line(point(i), point(2 * i + 1)));
			v_lines.push_back(new Line(point(i), point(2 * i + 2)));
		}
	}
}

void Binary_tree::draw_lines() const
{
	for (int i = 0; i < v_lines.size(); ++i)
	{
		v_lines[i].draw();
	}
	for (int i = 0; i < number_of_points(); ++i)
	{
		Circle c(point(i), r);
		c.set_fill_color(Color::blue);
		c.draw();
	}
}
