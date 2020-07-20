#ifndef BOOK_15_01_STDAFX_H
#define BOOK_15_01_STDAFX_H

#include <iostream>
#include <cmath>
#include "Graph.h"
#include "Simple_window.h"
constexpr int xmax = 600;
constexpr int ymax = 400;
constexpr int x_orig = xmax / 2;
constexpr int y_orig = ymax / 2;
const Point orig(x_orig, y_orig);
constexpr int r_min = -10;
constexpr int r_max = 11;
constexpr int n_points = 400;
constexpr int x_scale = 30;
constexpr int y_scale = 30;
constexpr int xlength = xmax - 40;
constexpr int ylength = ymax - 40;

double one(double)
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
