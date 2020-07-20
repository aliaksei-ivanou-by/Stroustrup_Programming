#ifndef TASK_16_09_CALCULATOR_WINDOW_H
#define TASK_16_09_CALCULATOR_WINDOW_H

#ifndef Task_16_09_STDAFX_H
#include "Task_16_09_stdafx.h"
#endif

#include "Task_16_09_Calculator.h"

namespace Graph_lib
{
	class Calculator_window : public Window
	{
	public:
		Calculator_window(Point xy, int w, int h, const string& title);
	private:
		Button calc_btn;

		In_box input;
		Out_box output;

		void calc_pressed();
		
		static void cb_calc_btn(Address, Address);

		Calc_lib::Calculator calculator;
	};
}

#endif