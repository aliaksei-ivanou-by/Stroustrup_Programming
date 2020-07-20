#ifndef TASK_14_11_BINARY_TREE_H
#define TASK_14_11_BINARY_TREE_H

#ifndef TASK_14_11_STDAFX_H
#include "Task_14_11_stdafx.h"
#endif

class Binary_tree : public Shape
{
public:
	Binary_tree(Point pp, int ll, int rr);
	void draw_lines() const;
protected:
	int r;
	int l;
	Vector_ref<Shape> v_lines;
};

#endif