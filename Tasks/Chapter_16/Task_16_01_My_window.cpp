#ifndef TASK_16_01_STDAFX_H
#include "Task_16_01_stdafx.h"
#include "Task_16_01_My_window.h"
#endif

Graph_lib::My_window::My_window(Point xy, int w, int h, const string& title)
	: Simple_window{ xy, w, h, title },
	quit_button{ Point(x_max() - 70, 30), 70, 20, "Quit", cb_quit }
{
	attach(quit_button);
}

void Graph_lib::My_window::cb_quit(Address, Address pw)
{
	reference_to<My_window>(pw).quit();
}

void Graph_lib::My_window::quit()
{
	hide();
}
