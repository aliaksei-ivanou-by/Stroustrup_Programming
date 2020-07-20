#pragma once
#ifndef TASK_13_10_REGULAR_POLYGON_H
#define TASK_13_10_REGULAR_POLYGON_H
#include "Simple_window.h"
#include "Graph.h"
#include <iostream>

constexpr double pi = 3.141592653589;

namespace Graph_lib
{
	class Regular_polygon : public Graph_lib::Polygon
	{
	public:
		Regular_polygon(Point c, int n, int d);
	private:
		Point c;
		int d;
		int n;
	};
}
#endif