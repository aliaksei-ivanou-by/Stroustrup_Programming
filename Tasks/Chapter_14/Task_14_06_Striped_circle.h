#ifndef TASK_14_06_STRIPTED_CIRCLE_H
#define TASK_14_06_STRIPTED_CIRCLE_H

#ifndef TASK_14_06_STDAFX_H
#include "Task_14_06_stdafx.h"
#endif

class Striped_circle : public Circle
{
public:
	Striped_circle(Point p, int r);
	void draw_lines() const;
private:
	Lines lines;
};

#endif