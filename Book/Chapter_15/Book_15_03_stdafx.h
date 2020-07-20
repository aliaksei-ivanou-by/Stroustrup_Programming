#ifndef BOOK_15_03_STDAFX_H
#define BOOK_15_03_STDAFX_H

#include <iostream>
#include "Graph.h"
#include "Simple_window.h"

constexpr int xmax = 600;
constexpr int ymax = 400;
constexpr int xoffset = 100;
constexpr int yoffset = 60;
constexpr int xspace = 40;
constexpr int yspace = 40;
constexpr int xlength = xmax - xoffset - xspace;
constexpr int ylength = ymax - yoffset - yspace;

constexpr int base_year = 1960;
constexpr int end_year = 2040;

constexpr double xscale = double(xlength) / (end_year - base_year);
constexpr double yscale = double(ylength) / 100;

#endif

#ifndef BOOK_15_03_DISTRIBUTION_H

#include "Book_15_03_Distribution.h"

#endif


#ifndef BOOK_15_03_SCALE_H

#include "Book_15_03_Scale.h"

#endif
