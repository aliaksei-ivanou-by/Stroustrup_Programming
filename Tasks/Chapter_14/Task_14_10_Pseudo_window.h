#ifndef TASK_14_10_PSEUDO_WINDOW_H
#define TASK_14_10_PSEUDO_WINDOW_H

#ifndef TASK_14_10_STDAFX_H
#include "Task_14_10_stdafx.h"
#endif

namespace Graph_lib
{
	class Pseudo_window : public Graph_lib::Box
	{
	public:
		Pseudo_window(Point pp, int ww, int hh, string str, string img_file);
		void draw_lines() const;
	private:
		Point p;
		int w;
		int h;
		Text s;
		Box window;
		Circle minimize;
		Circle maximize;
		Circle close;
		Image img;
		Line l;
	};
}

#endif
