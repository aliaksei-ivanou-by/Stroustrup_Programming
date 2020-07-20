#ifndef TASK_14_04_IMMOBILE_CIRCLE_H
#define TASK_14_04_IMMOBILE_CIRCLE_H

#ifndef TASK_14_04_STDAFX_H
#include "Task_14_04_stdafx.h"
#endif

struct Immobile_circle : Circle
{
	Immobile_circle(Point p, int r)
		: Circle(p, r)
	{
	}
	void move(int dx, int dy)
	{
	}
};


#endif