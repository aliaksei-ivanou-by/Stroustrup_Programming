#ifndef TASK_14_16_COTROLLER_COLOR_H
#define TASK_14_16_COTROLLER_COLOR_H

#ifndef TASK_14_16_STDAFX_H
#include "Task_14_16_stdafx.h"
#endif

namespace Graph_lib
{
	class Controller_Color : public Controller
	{
	public:
		using Controller::Controller;
		void set_mycolor();
	};
}

#endif