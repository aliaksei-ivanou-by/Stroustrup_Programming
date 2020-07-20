#ifndef TASK_15_11_STDAFX_H
#define TASK_15_11_STDAFX_H

#include <iostream>
#include "Graph.h"
#include "Simple_window.h"

constexpr int xmax = 900;
constexpr int ymax = 400;
constexpr int xoffset = 100;
constexpr int yoffset = 60;
constexpr int xspace = 40;
constexpr int yspace = 40;
constexpr int xlength = xmax - xoffset - xspace;
constexpr int ylength = ymax - yoffset - yspace;

constexpr int base_month = 1;
constexpr int end_month = 12;

constexpr double xscale = double(xlength) / (end_month - base_month);
constexpr double yscale = double(ylength) / 40;

#endif

#ifndef TASK_15_11_TEMPERATURE_H

#include "Task_15_11_Temperature.h"

#endif


#ifndef TASK_15_11_SCALE_H

#include "Task_15_11_Scale.h"

#endif
