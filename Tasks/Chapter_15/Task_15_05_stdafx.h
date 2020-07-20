#ifndef TASK_15_05_STDAFX_H
#define TASK_15_05_STDAFX_H

#include <iostream>
#include <cmath>
#include "Graph.h"
#include "Simple_window.h"

const int xmax = x_max() - 200;
const int ymax = y_max() - 200;
const int x_orig = xmax / 2;
const int y_orig = ymax / 2;
const Point orig(x_orig, y_orig);
constexpr int r_min = -10;
constexpr int r_max = 11;
constexpr int n_points = 400;
constexpr int x_scale = 10;
constexpr int y_scale = 10;
const int xlength = xmax - 40;
const int ylength = ymax - 40;

double leibniz(int n)
{
	double sum = 0;
	for (int i = 0; i <= n; ++i)
	{
		int j = 1;
		if (i % 2 != 0)
		{
			j = -1;
		}
		sum += 1 / double(2 * i + 1) * j;
	}
	std::cout << "n = " << n << "\tsum = " << sum << '\n';
	return sum;
}

#endif
