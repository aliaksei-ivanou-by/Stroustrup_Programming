#pragma once
#ifndef TASK_13_14_RIGHT_TRIANGLE_H
#define TASK_13_14_RIGHT_TRIANGLE_H
#include "Simple_window.h"
#include "Graph.h"
#include <ctime>

constexpr double pi = 3.141592653589;

namespace Graph_lib
{
	class Right_triangle : public Closed_polyline
	{
	public:
		Right_triangle(Point p, int side1, int side2, double angle = 0);
	private:
		int side1;
		int side2;
		double angle = 0;
		double alpha = 90;
	};
}
#endif