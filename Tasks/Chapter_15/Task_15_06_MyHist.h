#ifndef TASK_15_06_MYHIST_H
#define TASK_15_06_MYHIST_H

#ifndef Task_15_06_STDAFX_H
#include "Task_15_06_stdafx.h"
#endif

namespace Graph_lib
{
	class MyHist : public Shape
	{
	public:
		MyHist(Point orig, int xs, int ys);
		void add(double value);
		void draw_lines() const;
	private:
		int x_size;
		int y_size;
		vector<double> data;
		Vector_ref<Rectangle> rectangles;
	};
}

#endif