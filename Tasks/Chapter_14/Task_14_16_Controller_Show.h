#ifndef TASK_14_16_COTROLLER_SHOW_H
#define TASK_14_16_COTROLLER_SHOW_H

#ifndef TASK_14_16_STDAFX_H
#include "Task_14_16_stdafx.h"
#endif

namespace Graph_lib
{
	class Controller_Show : public Controller
	{
	public:
		using Controller::Controller;
		void show() const;
	};
}

#endif