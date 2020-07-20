#ifndef TASK_16_07_FLYING_AIRPLANE_H
#define TASK_16_07_FLYING_AIRPLANE_H

#ifndef Task_16_07_STDAFX_H
#include "Task_16_07_stdafx.h"
#endif

namespace Graph_lib
{
	class Flying_airplane : public Window
	{
	public:
		Flying_airplane(Point xy, int w, int h, const string& title);

		void fly();
		static void cb_fly(void*);
	private:
		Button start_btn;
		Button stop_btn;

		Image image;
		
		bool is_flying;
		
		static void cb_start_btn(Address, Address);
		static void cb_stop_btn(Address, Address);

		int dx = 1;
		int dy = 1;
		int ddx = 0;
		int ddy = 0;

		Point xy;
		int h;
		int w;
	};
}

#endif