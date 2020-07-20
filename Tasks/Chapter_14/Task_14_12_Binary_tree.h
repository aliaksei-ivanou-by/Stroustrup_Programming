#ifndef TASK_14_12_BINARY_TREE_H
#define TASK_14_12_BINARY_TREE_H

#ifndef TASK_14_12_STDAFX_H
#include "Task_14_12_stdafx.h"
#endif

class Binary_tree : public Shape
{
public:
	Binary_tree(Point pp, int ll, int rr);
	virtual void draw_lines() const;
protected:
	int r;
	int l;
	Vector_ref<Shape> v_lines;
};

#endif