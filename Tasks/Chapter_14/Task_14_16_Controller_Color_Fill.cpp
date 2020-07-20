#ifndef TASK_14_16_CONTROLLER_COLOR_FILL_H
#include "Task_14_16_stdafx.h"
#include "Task_14_16_Controller_Color_Fill.h"
#endif

namespace Graph_lib
{
	void Graph_lib::Controller_Color_Fill::set_myfill_color()
	{
		Color color = level;
		set_fill_color(color);
	}
}