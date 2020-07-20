#ifndef TASK_15_06_STDAFX_H
#include "Task_15_06_stdafx.h"
#include "Task_15_06_MyHist.h"
#endif

Graph_lib::MyHist::MyHist(Point orig, int xs, int ys)
	: x_size{ xs }, y_size{ ys }
{
	Shape::add(orig);
}

void Graph_lib::MyHist::add(double v)
{
	data.push_back(v);
	int bar_width = x_size / data.size();
	double data_max = 0;
	for (int i = 0; i <= rectangles.size(); ++i)
	{
		if (data[i] > data_max)
		{
			data_max = data[i];
		}
	}
	rectangles.clear();
	for (int i = 0; i < data.size(); ++i)
	{
		rectangles.push_back(new Rectangle(Point(point(0).x + bar_width * i, 
													point(0).y - data[i] / data_max * y_size), 
											0.9 * bar_width, 
											data[i] / data_max * y_size));
	}
}

void Graph_lib::MyHist::draw_lines() const
{
	for (int i = 0; i < rectangles.size(); ++i)
	{
		rectangles[i].draw_lines();
	}
}
