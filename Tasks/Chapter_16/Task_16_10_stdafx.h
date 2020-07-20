#ifndef Task_16_10_STDAFX_H
#define Task_16_10_STDAFX_H

#include <iostream>
#include "Graph.h"
#include "Simple_window.h"
#include "std_lib_facilities.h"

constexpr double pi = 3.141592653589;

const int xmax = x_max() - 200;
const int ymax = y_max() - 200;

constexpr int r_min = -10;
constexpr int r_max = 10;

constexpr int n_points = 400;

constexpr int x_scale = 20;
constexpr int y_scale = 20;

const int x_orig = xmax / 2;
const int y_orig = ymax / 2;
const Point orig(x_orig, y_orig);

const int xlength = xmax - 300;
const int ylength = ymax - 150;

#endif

#ifndef TASK_16_10_CHOICE_GRAPH_FUNCT_H

#include "Task_16_10_Choice_graph_funct.h"

#endif

#ifndef TASK_16_10_MYFUNCTION_H

#include "Task_16_10_MyFunction.h"

#endif