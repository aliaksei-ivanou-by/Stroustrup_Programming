#ifndef TASK_15_07_MYHIST_H
#define TASK_15_07_MYHIST_H

#ifndef Task_15_07_STDAFX_H
#include "Task_15_07_stdafx.h"
#endif

namespace Graph_lib
{
	class MyHist : public Shape
	{
	public:
		MyHist(Point orig, int xs, int ys);
		void add(double value);
		void set_bar_color(Color color, int bar);
		void set_bar_fill_color(Color color, int i);
		void set_bar_label(int i);
		void draw_lines() const;
		double get_idata(int i);
	private:
		int x_size;
		int y_size;
		vector<double> data;
		Vector_ref<Rectangle> rectangles;
		Vector_ref<Text> labels;
	};
}

#endif