#include "Task_13_04_ConPoints.h"

Point Graph_lib::n(const Graph_lib::Rectangle& r) // top
{
	return Point(r.point(0).x + r.width() / 2, 
		r.point(0).y);
}

Point Graph_lib::s(const Graph_lib::Rectangle& r) // bottom
{
	return Point(r.point(0).x + r.width() / 2, 
		r.point(0).y + r.height());
}

Point Graph_lib::e(const Graph_lib::Rectangle& r) // right
{
	return Point(r.point(0).x + r.width(), 
		r.point(0).y + r.height() / 2);
}

Point Graph_lib::w(const Graph_lib::Rectangle& r) // left
{
	return Point(r.point(0).x, 
		r.point(0).y + r.height() / 2);
}

Point Graph_lib::center(const Graph_lib::Rectangle& r) // center
{
	return Point(r.point(0).x + r.width() / 2, 
		r.point(0).y + r.height() / 2);
}
Point Graph_lib::ne(const Graph_lib::Rectangle& r) // top-right
{
	return Point(r.point(0).x + r.width(), 
		r.point(0).y);
}

Point Graph_lib::se(const Graph_lib::Rectangle& r) // bottom-right
{
	return Point(r.point(0).x + r.width(), 
		r.point(0).y + r.height());
}

Point Graph_lib::sw(const Graph_lib::Rectangle& r) // bottom-left
{
	return Point(r.point(0).x, 
		r.point(0).y + r.height());
}

Point Graph_lib::nw(const Graph_lib::Rectangle& r) // top-left
{
	return Point(r.point(0).x, 
		r.point(0).y);
}