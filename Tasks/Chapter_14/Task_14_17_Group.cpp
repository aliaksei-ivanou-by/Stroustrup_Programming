#ifndef TASK_14_17_GROUP_H
#include "Task_14_17_stdafx.h"
#include "Task_14_17_Group.h"
#endif

void Group::add(Shape* s)
{
	v_r.push_back(s);
}

void Group::set_color(Color color)
{
	for (int i = 0; i < v_r.size(); ++i)
	{
		v_r[i].set_color(color);
	}
}

void Group::set_fill_color(Color color)
{
	for (int i = 0; i < v_r.size(); ++i)
	{
		v_r[i].set_fill_color(color);
	}
}

void Group::draw_lines() const
{
	for (int i = 0; i < v_r.size(); ++i)
	{
		v_r[i].draw();
	}
}