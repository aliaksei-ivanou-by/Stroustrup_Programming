#ifndef TASK_14_01_SMILEY_H
#define TASK_14_01_SMILEY_H

#ifndef TASK_14_01_STDAFX_H
#include "Task_14_01_stdafx.h"
#endif

class Smiley : public Circle
{
public:
	Smiley(Point p, int rr);
	void draw_lines() const;
private:
	Graph_lib::Ellipse eye_L;
	Graph_lib::Ellipse eye_R;
	Graph_lib::Arc mouth;
};

#endif