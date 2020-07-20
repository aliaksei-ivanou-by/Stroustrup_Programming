#ifndef TASK_15_08_MYHIST_H
#define TASK_15_08_MYHIST_H

#ifndef Task_15_08_STDAFX_H
#include "Task_15_08_stdafx.h"
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
		void set_bar_label(std::string l, int i);
		void draw_lines() const;
		double get_idata(int i);
		std::string set_x_label(std::string x_label);
		std::string set_y_label(std::string y_label);
	private:
		int x_size;
		int y_size;
		vector<double> data;
		Vector_ref<Rectangle> rectangles;
		Vector_ref<Text> labels;
		std::string x_label;
		std::string y_label;
	};
}

#endif