#ifndef TASK_14_01_FROWNY_H
#define TASK_14_01_FROWNY_H

#ifndef TASK_14_01_STDAFX_H
#include "Task_14_01_stdafx.h"
#endif

class Frowny : public Circle
{
public:
	Frowny(Point p, int rr);
	void draw_lines() const;
private:
	Graph_lib::Ellipse eye_L;
	Graph_lib::Ellipse eye_R;
	Graph_lib::Arc mouth;
};

#endif