#ifndef TASK_16_10_CHOICE_GRAPH_FUNCT_H
#define TASK_16_10_CHOICE_GRAPH_FUNCT_H

#ifndef TASK_16_10_STDAFX_H
#include "Task_16_10_stdafx.h"
#endif

namespace Graph_lib
{
	class Choice_graph_funct : public Window
	{
	public:
		Choice_graph_funct(Point xy, int w, int h, const string& title);
	private:
		Axis x_axis;
		Axis y_axis;
		MyFunction func;
		double (*func_ptr)(double);
		vector<std::pair<double (*)(double), string>> v_func;
		In_box r1_in;
		In_box r2_in;
		In_box n_points_in;
		In_box x_scale_in;
		In_box y_scale_in;

		Button draw_btn;
		Menu menu_func;

		void get_functions();

		void draw_btn_pressed();
		int get_n_func();
		void func_pressed(int key);

		static void cb_draw_btn(Address, Address);
	};
}

#endif