#ifndef TASK_14_13_BINARY_TREE_H
#define TASK_14_13_BINARY_TREE_H

#ifndef TASK_14_13_STDAFX_H
#include "Task_14_13_stdafx.h"
#endif

class Binary_tree : public Shape
{
public:
	Binary_tree(Point pp, int ll, int rr, int line_type = 1, Color line_color = Color::black);
	virtual void draw_lines() const;
protected:
	int r;
	int l;
	Vector_ref<Shape> v_lines;
};

#endif