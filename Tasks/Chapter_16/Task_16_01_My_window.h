#ifndef TASK_16_01_MY_WINDOW_H
#define TASK_16_01_MY_WINDOW_H

#ifndef TASK_16_01_STDAFX_H
#include "Task_16_01_stdafx.h"
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
}

#endif