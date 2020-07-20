#ifndef TASK_14_09_GROUP_H
#define TASK_14_09_GROUP_H

#ifndef TASK_14_17_STDAFX_H
#include "Task_14_17_stdafx.h"
#endif

class Group : public Shape
{
public:
	Group()
	{}
	void add(Shape* s);
	void set_color(Color color);
	void set_fill_color(Color color);
	void draw_lines() const;
private:
	Vector_ref<Shape> v_r;
};

#endif