#ifndef TASK_15_07_STDAFX_H
#define TASK_15_07_STDAFX_H

#include <iostream>
#include <ctime>
#include "Graph.h"
// add to Graph.h function for Vector_ref (public) : void clear() { v.clear(); }
#include "Simple_window.h"

const int xmax = x_max() - 100;
const int ymax = y_max() - 100;

constexpr int r_min = -10;
constexpr int r_max = 10;

constexpr int n_points = 400;

constexpr int x_scale = 20;
constexpr int y_scale = 20;

const int x_orig = xmax / 2;
const int y_orig = ymax / 2;
const Point orig(x_orig, y_orig);

const int xlength = xmax - 200;
const int ylength = ymax - 200;

#endif

#ifndef TASK_15_07_MYHIST_H

#include "Task_15_07_MyHist.h"

#endif