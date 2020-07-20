#pragma once
#ifndef TASK_13_01_ARC_H
#define TASK_13_01_ARC_H
#include "Simple_window.h"
#include "Graph.h"
using namespace Graph_lib;

namespace Graph_lib
{
	class Arc : public Graph_lib::Shape
	{
	public:
		Arc(Point center, int width, int height, double start, double end);
		void draw_lines() const;
	private:
		int width;
		int height;
		double start;
		double end;
	};
}
#endif