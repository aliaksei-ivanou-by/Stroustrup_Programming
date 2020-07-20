#ifndef TASK_15_04_STDAFX_H
#define TASK_15_04_STDAFX_H

#include <iostream>
#include <cmath>
#include "Graph.h"
#include "Simple_window.h"

const int xmax = x_max() - 200;
const int ymax = y_max() - 200;
const int x_orig = xmax / 2;
const int y_orig = ymax / 2;
const Point orig(x_orig, y_orig);
constexpr int n_points = 400;
const int x_scale = 10;
const int y_scale = 10;
const int xlength = xmax - 40;
const int ylength = ymax - 40;
const int r_min = -x_orig / x_scale;
const int r_max = x_orig / x_scale;

double sum_sin_cos(double x)
{
	return sin(x) + cos(x);
}

double sum_sq_sin_cos(double x)
{
	return sin(x) * sin(x) + cos(x) * cos(x);
}

#endif
