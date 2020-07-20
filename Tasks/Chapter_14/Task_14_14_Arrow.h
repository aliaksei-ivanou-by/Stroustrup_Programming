#ifndef TASK_14_14_ARROW_H
#define TASK_14_14_ARROW_H

#ifndef TASK_14_14_STDAFX_H
#include "Task_14_14_stdafx.h"
#endif

class Arrow : public Graph_lib::Shape
{
public:
	Arrow(Point p1, Point p2);
	Arrow(Point p1, Point p2, Color line_color);
	void draw_lines() const;
private:
	int size = 10;
	int delta = 20;
};

#endif