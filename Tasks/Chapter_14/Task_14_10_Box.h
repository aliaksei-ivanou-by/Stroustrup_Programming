#ifndef TASK_14_10_BOX_H
#define TASK_14_10_BOX_H

#ifndef TASK_14_10_STDAFX_H
#include "Task_14_10_stdafx.h"
#endif

namespace Graph_lib
{
	class Box : public Graph_lib::Shape
	{
	public:
		Box(Point p, int ww, int hh);
		void draw_lines() const;
	protected:
		Box()
		{};
	private:
		int w;
		int h;
	};
}

#endif