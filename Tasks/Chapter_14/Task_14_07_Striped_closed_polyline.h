#ifndef TASK_14_07_STRIPED_CLOSED_POLYLINE_H
#define TASK_14_07_STRIPED_CLOSED_POLYLINE_H

#ifndef TASK_14_07_STDAFX_H
#include "Task_14_07_stdafx.h"
#endif

namespace Graph_lib
{
	class Striped_closed_polyline : public Closed_polyline
	{
	public:
		Striped_closed_polyline(int d);
		void draw_lines() const;
	private:
		int d;
	};

	bool on_line(Point p1, Point p2, Point point);
}


#endif