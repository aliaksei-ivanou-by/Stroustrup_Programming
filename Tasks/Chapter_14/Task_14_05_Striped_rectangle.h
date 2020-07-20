#ifndef TASK_14_05_STRIPTED_RECTANGLE_H
#define TASK_14_05_STRIPTED_RECTANGLE_H

#ifndef TASK_14_05_STDAFX_H
#include "Task_14_05_stdafx.h"
#endif

class Striped_rectangle : public Rectangle
{
public:
	Striped_rectangle(Point p, int rec_w, int rec_h);
	void draw_lines() const;
private:
	Lines lines;
};

#endif