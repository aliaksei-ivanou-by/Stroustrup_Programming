#ifndef TASK_14_16_COTROLLER_H
#define TASK_14_16_COTROLLER_H

#ifndef TASK_14_16_STDAFX_H
#include "Task_14_16_stdafx.h"
#endif

namespace Graph_lib
{
	class Controller : public Shape
	{
	public:
		Controller(bool s, int l)
			: status{ s }, level{ l }
		{}
		virtual void on();
		virtual void off();
		virtual void set_level(int l);
		virtual void show() const;
	protected:
		bool status;
		int level;
	};
}
#endif