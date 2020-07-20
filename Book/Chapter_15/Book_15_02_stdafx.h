#ifndef BOOK_15_02_STDAFX_H
#define BOOK_15_02_STDAFX_H

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

double fac(int n)
{
	double r = 1;
	while (n > 1)
	{
		r *= n;
		--n;
	}
	return r;
}

double term(double x, int n)
{
	return pow(x, n) / fac(n);
}

double expe(double x, int n)
{
	double sum = 0;
	for (int i = 0; i < n; ++i)
	{
		sum += term(x, i);
	}
	return sum;
}

int expN_number_of_terms = 10;

double expN(double x)
{
	return expe(x, expN_number_of_terms);
}

#endif
