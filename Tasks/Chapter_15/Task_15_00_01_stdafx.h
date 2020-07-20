#ifndef TASK_15_00_01_STDAFX_H
#define TASK_15_00_01_STDAFX_H

#include <iostream>
#include "Graph.h"
#include "Simple_window.h"

constexpr int xmax = 600;
constexpr int ymax = 600;

constexpr int r_min = -10;
constexpr int r_max = 11;

constexpr int n_points = 400;

constexpr int x_scale = 20;
constexpr int y_scale = 20;

constexpr int x_orig = xmax / 2;
constexpr int y_orig = ymax / 2;
const Point orig(x_orig, y_orig);

constexpr int xlength = xmax - 200;
constexpr int ylength = ymax - 200;

double one(double x)
{
	return 1;
}

double slope(double x)
{
	return x / 2;
}

double square(double x)
{
	return x * x;
}

double sloping_cos(double x)
{
	return cos(x) + slope(x);
}

#endif
