#include "Task_13_05_ConPoints.h"

// Circle

Point Graph_lib::n(const Graph_lib::Circle& c) // top
{
	return Point(c.point(0).x + c.radius(), 
		c.point(0).y);
}

Point Graph_lib::s(const Graph_lib::Circle& c) // bottom
{
	return Point(c.point(0).x + c.radius(), 
		c.point(0).y + c.radius() * 2);
}

Point Graph_lib::e(const Graph_lib::Circle& c) // right
{
	return Point(c.point(0).x + c.radius() * 2, 
		c.point(0).y + c.radius());
}

Point Graph_lib::w(const Graph_lib::Circle& c) // left
{
	return Point(c.point(0).x, 
		c.point(0).y + c.radius());
}

Point Graph_lib::center(const Graph_lib::Circle& c) // center
{
	return c.center();
}
Point Graph_lib::ne(const Graph_lib::Circle& c) // top-right
{
	return Point(c.center().x + c.radius() * cos(315 * pi / 180),
		c.center().y + c.radius() * sin(315 * pi / 180));
}

Point Graph_lib::se(const Graph_lib::Circle& c) // bottom-right
{
	return Point(c.center().x + c.radius() * cos(45 * pi / 180),
		c.center().y + c.radius() * sin(45 * pi / 180));
}

Point Graph_lib::sw(const Graph_lib::Circle& c) // bottom-left
{
	return Point(c.center().x + c.radius() * cos(135 * pi / 180), 
		c.center().y + c.radius() * sin(135 * pi / 180));
}

Point Graph_lib::nw(const Graph_lib::Circle& c) // top-left
{
	return Point(c.center().x + c.radius() * cos(225 * pi / 180),
		c.center().y + c.radius() * sin(225 * pi / 180));
}

// Ellipse
Point Graph_lib::n(const Graph_lib::Ellipse& e) // top
{
	return Point(e.point(0).x + e.major(), 
		e.point(0).y);
}

Point Graph_lib::s(const Graph_lib::Ellipse& e) // bottom
{
	return Point(e.point(0).x + e.major(), 
		e.point(0).y + e.minor() * 2);
}

Point Graph_lib::e(const Graph_lib::Ellipse& e) // right
{
	return Point(e.point(0).x + e.major() * 2,
		e.point(0).y + e.minor());
}

Point Graph_lib::w(const Graph_lib::Ellipse& e) // left
{
	return Point(e.point(0).x,
		e.point(0).y + e.minor());
}

Point Graph_lib::center(const Graph_lib::Ellipse& e) // center
{
	return e.center();	
}
Point Graph_lib::ne(const Graph_lib::Ellipse& e) // top-right
{
	return Point(e.center().x + e.major() * cos((-45) * pi / 180),
		e.center().y + e.minor() * sin((-45) * pi / 180));
}

Point Graph_lib::se(const Graph_lib::Ellipse& e) // bottom-right
{
	return Point(e.center().x + e.major() * cos(45 * pi / 180),
		e.center().y + e.minor() * sin(45 * pi / 180));
}

Point Graph_lib::sw(const Graph_lib::Ellipse& e) // bottom-left
{
	return Point(e.center().x + e.major() * cos(135 * pi / 180),
		e.center().y + e.minor() * sin(135 * pi / 180));
}

Point Graph_lib::nw(const Graph_lib::Ellipse& e) // top-left
{
	return Point(e.center().x + e.major() * cos(225 * pi / 180),
		e.center().y + e.minor() * sin(225 * pi / 180));
}