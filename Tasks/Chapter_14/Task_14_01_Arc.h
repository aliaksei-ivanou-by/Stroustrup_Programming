#ifndef TASK_14_01_ARC_H
#define TASK_14_01_ARC_H

#ifndef TASK_14_01_STDAFX_H
#include "Task_14_01_stdafx.h"
#endif

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