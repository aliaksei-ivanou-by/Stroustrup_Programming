#pragma once
#ifndef TASK_13_06_BOX_TEXT_H
#define TASK_13_06_BOX_TEXT_H
#include "Simple_window.h"
#include "Graph.h"
#include <iostream>
#include "Task_13_06_Box.h"

constexpr double pi = 3.141592653589;

namespace Graph_lib
{
	class Box_text : public Rectangle
	{
	public:
		Box_text(Point pp, string ss);
		void draw_lines() const;
	private:
		Text text;
	};
}
#endif