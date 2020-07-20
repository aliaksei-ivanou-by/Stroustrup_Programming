#ifndef TASK_14_17_BOX_TEXT_H
#define TASK_14_17_BOX_TEXT_H

#ifndef TASK_14_17_STDAFX_H
#include "Task_14_17_stdafx.h"
#endif

namespace Graph_lib
{
	class Box_text : public Rectangle
	{
	public:
		Box_text(Point pp, string ss);
		void draw_lines() const;
	private:
		Text text;
	};
}

#endif