#pragma once
#ifndef TASK_13_02_BOX_H
#define TASK_13_02_BOX_H
#include "Simple_window.h"
#include "Graph.h"

namespace Graph_lib
{
	class Box : public Graph_lib::Shape
	{
	public:
		Box(Point p, int ww, int hh);
		void draw_lines() const;
	private:
		int w;
		int h;
	};
}
#endif