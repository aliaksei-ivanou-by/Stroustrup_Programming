#ifndef TASK_16_09_STDAFX_H
#include "Task_16_09_stdafx.h"
#include "Task_16_09_Calculator_window.h"
#endif

Graph_lib::Calculator_window::Calculator_window(Point xy, int w, int h, const string& title)
	: Window(xy, w, h, title), 
	calc_btn{ Point(0, 0), x_max(), 20, "Calculate", cb_calc_btn }, 
	input{ Point(80, 40), x_max() - 100, 30, "Input: " }, 
	output{ Point(80, 80), x_max() - 100, 30, "Output: " }
{
	attach(calc_btn);
	attach(input);
	attach(output);
}

void Graph_lib::Calculator_window::calc_pressed()
{
	string result = calculator.calculate(input.get_string());
	output.put(result);
}

void Graph_lib::Calculator_window::cb_calc_btn(Address, Address pw)
{
	reference_to<Calculator_window>(pw).calc_pressed();
}
