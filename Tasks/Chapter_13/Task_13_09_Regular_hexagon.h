#pragma once
#ifndef TASK_13_09_REGULAR_HEXAGON_H
#define TASK_13_09_REGULAR_HEXAGON_H
#include "Simple_window.h"
#include "Graph.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

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

Graph_lib::Vector_ref<Regular_hexagon> hexagons(Point c, int d, int n_y, int n_x);
#endif