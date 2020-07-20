#ifndef TASK_16_04_REGULAR_POLYGON_H
#define TASK_16_04_REGULAR_POLYGON_H

#ifndef TASK_16_04_STDAFX_H
#include "Task_16_04_stdafx.h"
#endif

namespace Graph_lib
{
	class Regular_polygon : public Graph_lib::Polygon
	{
	public:
		Regular_polygon(Point c, int n, int d);
	private:
		Point c;
		int d;
		int n;
	};
}
#endif