#ifndef TASK_15_06_STDAFX_H
#define TASK_15_06_STDAFX_H

#include <iostream>
#include <ctime>
#include "Graph.h"
// add to Graph.h function for Vector_ref (public) : void clear() { v.clear(); }
#include "Simple_window.h"

constexpr int xmax = 600;
constexpr int ymax = 600;

constexpr int r_min = -10;
constexpr int r_max = 10;

constexpr int n_points = 400;

constexpr int x_scale = 20;
constexpr int y_scale = 20;

constexpr int x_orig = xmax / 2;
constexpr int y_orig = ymax / 2;
const Point orig(x_orig, y_orig);

constexpr int xlength = xmax - 200;
constexpr int ylength = ymax - 200;

#endif

#ifndef TASK_15_06_MYHIST_H

#include "Task_15_06_MyHist.h"

#endif