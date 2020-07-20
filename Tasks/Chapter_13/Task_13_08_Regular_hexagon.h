#pragma once
#ifndef TASK_13_08_REGULAR_HEXAGON_H
#define TASK_13_08_REGULAR_HEXAGON_H
#include "Simple_window.h"
#include "Graph.h"
#include <iostream>

constexpr double pi = 3.141592653589;

namespace Graph_lib
{
	class Regular_hexagon : public Graph_lib::Polygon
	{
	public:
		Regular_hexagon(Point c, int d);
	private:
		Point c;
		int d;
		const int n = 6;
	};
}
#endif