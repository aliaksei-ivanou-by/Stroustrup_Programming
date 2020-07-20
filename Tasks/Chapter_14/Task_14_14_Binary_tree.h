#ifndef TASK_14_14_BINARY_TREE_H
#define TASK_14_14_BINARY_TREE_H

#ifndef TASK_14_14_STDAFX_H
#include "Task_14_14_stdafx.h"
#endif

class Binary_tree : public Shape
{
public:
	Binary_tree(Point pp, int ll, int rr, int line_type = 1, Color line_color = Color::black);
	virtual void draw_lines() const;
	void set_label(std::string text, std::string p);
protected:
	int r;
	int l;
	Vector_ref<Shape> v_lines;
	Vector_ref<Text> v_labels;
};

#endif