#ifndef TASK_16_02_BUTTON_BOARD_H
#define TASK_16_02_BUTTON_BOARD_H

#ifndef TASK_16_02_STDAFX_H
#include "Task_16_02_stdafx.h"
#endif

namespace Graph_lib
{
	class My_window : public Simple_window
	{
	public:
		My_window(Point xy, int w, int h, const string& title);
	private:
		Button quit_button;
		static void cb_quit(Address, Address);
		void quit();
	};

	class Button_board : public My_window
	{
	public:
		Button_board(Point xy, int w, int h, const string& title, int table_row, int table_column);
	private:
		vector<vector<Button*>> buttons;
		int table_column;
		int table_row;
		Out_box xy_out;

		int i = 0;
		int j = 0;

		std::string select_button();
		void select_label(string);
	};
}

#endif