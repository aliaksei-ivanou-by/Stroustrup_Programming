#ifndef TASK_14_07_STRIPED_CLOSED_POLYLINE_H
#include "Task_14_07_stdafx.h"
#include "Task_14_07_Striped_closed_polyline.h"
#endif

bool Graph_lib::on_line(Point p1, Point p2, 
	Point pp)
{
	int dx = p2.x - p1.x;
	int dy = p2.y - p1.y;
	int dx_p = pp.x - p1.x;
	int dy_p = pp.y - p1.y;
	if (!(dx_p * dy - dx * dy_p))
	{
		if (abs(dx) > abs(dy))
		{
			if (dx > 0)
			{
				return (p1.x <= pp.x && pp.x <= p2.x);
			}
			else
			{
				return (p2.x <= pp.x && pp.x <= p1.x);
			}
		}
		else
		{
			if (dy > 0)
			{
				return (p1.y <= pp.y && pp.y <= p2.y);
			}
			else
			{
				return (p2.y <= pp.y && pp.y <= p1.y);
			}
		}
	}
	return false;
}

bool intersection(Point p1, Point p2, 
	Point p3, Point p4, 
	Point& pp)
{
	double x1 = p1.x;
	double x2 = p2.x;
	double x3 = p3.x;
	double x4 = p4.x;
	double y1 = p1.y;
	double y2 = p2.y;
	double y3 = p3.y;
	double y4 = p4.y;
	double d1 = (x4 - x3) * (y1 - y3) - (y4 - y3) * (x1 - x3);
	double d2 = (x2 - x1) * (y1 - y3) - (y2 - y1) * (x1 - x3);
	if (((y4 - y3) * (x2 - x1) - (x4 - x3) * (y2 - y1)) == 0 && d1 != 0 && d2 != 0)
	{
		return false;
	}
	d1 = d1 / ((y4 - y3) * (x2 - x1) - (x4 - x3) * (y2 - y1));
	d2 = d2 / ((y4 - y3) * (x2 - x1) - (x4 - x3) * (y2 - y1));
	if (d1 < 0 || d1 > 1 || d2 < 0 || d2 > 1)
	{
		return false;
	}
	pp.x = x1 + d1 * (x2 - x1);
	pp.y = y1 + d1 * (y2 - y1);
	return true;
}

Graph_lib::Striped_closed_polyline::Striped_closed_polyline(int dd)
	:d{ dd }
{
	
}

void Graph_lib::Striped_closed_polyline::draw_lines() const
{
	Closed_polyline::draw_lines();
	int x_min = point(0).x;
	int y_min = point(0).y;
	int x_max = point(0).x;
	int y_max = point(0).y;
	vector<Point> v_lines;
	for (int i = 1; i < number_of_points(); ++i)
	{
		if (point(i).x < x_min)
		{
			x_min = point(i).x;
		}
		if (point(i).y < x_min)
		{
			y_min = point(i).y;
		}
		if (point(i).x > x_max)
		{
			x_max = point(i).x;
		}
		if (point(i).y > y_max)
		{
			y_max = point(i).y;
		}
	}
	for (int y = y_min + d; y < y_max; y += d)
	{
		Point pp;
		Point pp_back(0, 0);
		for (int i = 1; i < number_of_points(); ++i)
		{
			if (intersection(Point(x_min, y), Point(x_max, y),
				point(i - 1), point(i),
				pp))
			{
				if (pp != pp_back)
				{
					v_lines.push_back(pp);
					pp_back.x = pp.x;
					pp_back.y = pp.y;
				}
			}
		}
		if (intersection(Point(x_min, y), Point(x_max, y), 
			point(number_of_points() - 1), point(0), 
			pp))
			
		{
			if (pp != pp_back)
			{
				v_lines.push_back(pp);
				pp_back.x = pp.x;
				pp_back.y = pp.y;
			}
		}
	}
	for (int i = 1; i < v_lines.size(); i += 2)
	{
		Line l(v_lines[i], v_lines[i - 1]);
		l.draw();
	}
}