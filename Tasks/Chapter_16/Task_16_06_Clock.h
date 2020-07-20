#ifndef TASK_16_06_CLOCK_H
#define TASK_16_06_CLOCK_H

#ifndef TASK_16_06_STDAFX_H
#include "Task_16_06_stdafx.h"
#endif

namespace Graph_lib
{
	class MyLine : public Shape
	{
	public:
		MyLine(Point p1, Point p2);
		void set_point(int i, Point p);
	};

	class Clock : public Window, public Shape
	{
	public:
		Clock(Point xy, int w, int h, const string& title);
		void run_clock();
		static void cb_run_clock(void* clock);
		int get_seconds();
		int get_minutes();
		int get_hours();
	private:
		int r;
		Circle clock;
		Circle center;
		MyLine seconds;
		MyLine minutes;
		MyLine hours;
		int w;
		int h;
	};
}

#endif