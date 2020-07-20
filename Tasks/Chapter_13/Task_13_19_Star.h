#pragma once
#ifndef TASK_13_19_STAR_H
#define TASK_13_19_STAR_H
#include "Simple_window.h"
#include "Graph.h"
#include <iostream>

constexpr double pi = 3.141592653589;

namespace Graph_lib
{
	class Star : public Polygon
	{
	public:
		Star(Point c, int n, int r);
		Point find_distance(Point p1, Point p2, int d);
	private:
		Point c; // center
		int n; // points
		int r; // radius
	};
}
#endif