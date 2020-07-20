#ifndef TASK_16_08_CURRENCY_CONVERTER_H
#define TASK_16_08_CURRENCY_CONVERTER_H

#ifndef TASK_16_08_STDAFX_H
#include "Task_16_08_stdafx.h"
#endif

namespace Graph_lib
{
	class Currency_converter : public Window
	{
	public:
		Currency_converter(Point xy, int w, int h, const string& title);
	private:
		In_box amount_in;
		Out_box amount_out;

		Text text_from;
		Text  text_to;

		Menu menu_from;
		Menu menu_to;

		int from_cur;
		int to_cur;
		vector<vector<double>> rates;
		vector<string> currencies;
		void get_rates();
		void get_currencies();

		int from_cur_pressed();
		void set_label_from(int currency);
		int to_cur_pressed();
		void set_label_to(int currency);
		void calculate();
	};
}

#endif