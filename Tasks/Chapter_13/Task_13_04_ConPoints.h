#pragma once
#ifndef TASK_13_04_CONPOINTS_H
#define TASK_13_04_CONPOINTS_H
#include "Simple_window.h"
#include "Graph.h"

namespace Graph_lib
{
	Point n(const Graph_lib::Rectangle& r); // top
	Point s(const Graph_lib::Rectangle& r); // bottom
	Point e(const Graph_lib::Rectangle& r); // right
	Point w(const Graph_lib::Rectangle& r); // left
	Point center(const Graph_lib::Rectangle& r); // center
	Point ne(const Graph_lib::Rectangle& r); // top-right
	Point se(const Graph_lib::Rectangle& r); // bottom-right
	Point sw(const Graph_lib::Rectangle& r); // bottom-left
	Point nw(const Graph_lib::Rectangle& r); // top-left
}
#endif