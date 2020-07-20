#pragma once
#ifndef TASK_13_03_ARROW_H
#define TASK_13_03_ARROW_H
#include "Graph.h"
using namespace Graph_lib;

class Arrow : public Graph_lib::Shape
{
public:
	Arrow(Point p1, Point p2);
	void draw_lines() const;
	void set_size(int s)
	{
		size = s;
	}
private:
	int size = 10;
	int delta = 20;
};
#endif