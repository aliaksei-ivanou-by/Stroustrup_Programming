#include "Task_13_14_Right_triangle.h"

Right_triangle::Right_triangle(Point p, int s1, int s2, double a)
	: side1{ s1 }, side2{ s2 }, angle{ a }, alpha{ 90 - a }
{
	add(p);

	int x = p.x + cos(angle * pi / 180) * side1;
	int y = p.y - sin(angle * pi / 180) * side1;
	add(Point(x, y));

	x = p.x - cos(alpha * pi / 180) * side2;
	y = p.y - sin(alpha * pi / 180) * side2;
	add(Point(x, y));
}