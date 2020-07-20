#ifndef TASK_14_12_BINARY_TREE_RECTANGLE_H
#include "Task_14_12_stdafx.h"
#include "Task_14_12_Binary_tree_Rectangle.h"
#endif

void Binary_tree_Rectangle::draw_lines() const
{
	for (int i = 0; i < number_of_points(); ++i)
	{
		Graph_lib::Rectangle rec(point(i), r, r);
		rec.set_fill_color(Color::blue);
		rec.draw();
	}
	for (int i = 0; i < v_lines.size(); ++i)
	{
		v_lines[i].draw();
	}
}
