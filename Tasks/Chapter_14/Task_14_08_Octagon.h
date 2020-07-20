#ifndef TASK_14_08_OCTAGON_H
#define TASK_14_08_OCTAGON_H

#ifndef TASK_14_08_STDAFX_H
#include "Task_14_08_stdafx.h"
#endif

class Octagon : public Graph_lib::Polygon
{
public:
	Octagon(Point c, int d);
private:
	Point cen;
	int d;
	const int n = 8;
};

#endif