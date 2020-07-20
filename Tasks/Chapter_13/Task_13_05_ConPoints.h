#pragma once
#ifndef TASK_13_05_CONPOINTS_H
#define TASK_13_05_CONPOINTS_H
#include "Simple_window.h"
#include "Graph.h"
#include <cmath>

constexpr double pi = 3.141592653589;

namespace Graph_lib
{
	// Circle
	Point n(const Graph_lib::Circle& c); // top
	Point s(const Graph_lib::Circle& c); // bottom
	Point e(const Graph_lib::Circle& c); // right
	Point w(const Graph_lib::Circle& c); // left
	Point center(const Graph_lib::Circle& c); // center
	Point ne(const Graph_lib::Circle& c); // top-right
	Point se(const Graph_lib::Circle& c); // bottom-right
	Point sw(const Graph_lib::Circle& c); // bottom-left
	Point nw(const Graph_lib::Circle& c); // top-left
	// Ellipse
	Point n(const Graph_lib::Ellipse& e); // top
	Point s(const Graph_lib::Ellipse& e); // bottom
	Point e(const Graph_lib::Ellipse& e); // right
	Point w(const Graph_lib::Ellipse& e); // left
	Point center(const Graph_lib::Ellipse& e); // center
	Point ne(const Graph_lib::Ellipse& e); // top-right
	Point se(const Graph_lib::Ellipse& e); // bottom-right
	Point sw(const Graph_lib::Ellipse& e); // bottom-left
	Point nw(const Graph_lib::Ellipse& e); // top-left
}
#endif