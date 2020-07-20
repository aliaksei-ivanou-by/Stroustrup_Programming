#pragma once
#ifndef TASK_13_18_POLY_H
#define TASK_13_18_POLY_H
#include "Simple_window.h"
#include "Graph.h"

class Poly : public Polygon
{
public:
	Poly(vector<Point> v_p);
	void add(Point p);
	void draw_lines() const;
};
#endif