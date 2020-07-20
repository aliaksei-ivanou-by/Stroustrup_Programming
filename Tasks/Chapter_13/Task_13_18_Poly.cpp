#include "Task_13_18_Poly.h"

Poly::Poly(vector<Point> v_p)
{
	for (int i = 0; i < v_p.size(); ++i)
	{
		add(v_p[i]);
	}
}

void Poly::add(Point p)
{
	Polygon::add(p);
}

void Poly::draw_lines() const
{
	Polygon::draw_lines();
}