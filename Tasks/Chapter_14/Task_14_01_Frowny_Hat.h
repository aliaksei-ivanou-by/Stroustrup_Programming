#ifndef TASK_14_01_FROWNY_HAT_H
#define TASK_14_01_FROWNY_HAT_H

#ifndef TASK_14_01_STDAFX_H
#include "Task_14_01_stdafx.h"
#endif

class Frowny_Hat : public Frowny
{
public:
	Frowny_Hat(Point p, int rr);
	void draw_lines() const;
private:
	Graph_lib::Polygon hat;
};

#endif