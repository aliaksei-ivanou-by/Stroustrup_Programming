#ifndef TASK_15_09_STDAFX_H
#include "Task_15_09_stdafx.h"
#include "Task_15_09_MyHist.h"
#endif

Graph_lib::MyHist::MyHist(Point orig, int xs, int ys)
	: x_size{ xs }, y_size{ ys }
{
	Shape::add(orig);
}

void Graph_lib::MyHist::add(double v)
{
	data.push_back(v);
	labels.push_back(new Text(Point(0, 0), ""));
	int bar_width = x_size / data.size();
	Vector_ref<Text> labels_;
	for (int i = 0; i < labels.size(); ++i)
	{
		labels_.push_back(labels[i]);
	}
	vector<Color> colors;
	vector<Color> colors_fill;
	double data_max = 0;
	for (int i = 0; i <= rectangles.size(); ++i)
	{
		if (i != rectangles.size())
		{
			colors.push_back(rectangles[i].color());
			colors_fill.push_back(rectangles[i].fill_color());
		}
		if (data[i] > data_max)
		{
			data_max = data[i];
		}
	}
	rectangles.clear();
	labels.clear();
	for (int i = 0; i < data.size(); ++i)
	{
		rectangles.push_back(new Rectangle(Point(point(0).x + bar_width * i,
			point(0).y - data[i] / data_max * y_size),
			0.9 * bar_width,
			data[i] / data_max * y_size));
		if ((i == 0) || (i % 6 == 0))
		{
			labels.push_back(new Text(Point(rectangles[i].point(0).x,
				point(0).y + y_size * 0.6),
				labels_[i].label()));
		}
		else
		{
			if ((i + 5) % 6 == 0)
			{
				labels.push_back(new Text(Point(rectangles[i].point(0).x + 2,
					point(0).y + y_size * 0.5),
					labels_[i].label()));
			}
			else
			{
				if ((i + 4) % 6 == 0)
				{
					labels.push_back(new Text(Point(rectangles[i].point(0).x + 2,
						point(0).y + y_size * 0.4),
						labels_[i].label()));
				}
				else
				{
					if ((i + 3) % 6 == 0)
					{
						labels.push_back(new Text(Point(rectangles[i].point(0).x + 2,
							point(0).y + y_size * 0.3),
							labels_[i].label()));
					}
					else
					{
						if ((i + 2) % 6 == 0)
						{
							labels.push_back(new Text(Point(rectangles[i].point(0).x + 2,
								point(0).y + y_size * 0.2),
								labels_[i].label()));
						}
						else
						{
							labels.push_back(new Text(Point(rectangles[i].point(0).x + 2,
								point(0).y + y_size * 0.1),
								labels_[i].label()));
						}
					}
				}
			}
		}
	}
	for (int i = 0; i < colors.size(); ++i)
	{
		rectangles[i].set_color(colors[i]);
		rectangles[i].set_fill_color(colors_fill[i]);
	}
}

void Graph_lib::MyHist::set_bar_color(Color c, int i)
{
	rectangles[i].set_color(c);
}

void Graph_lib::MyHist::set_bar_fill_color(Color c, int i)
{
	rectangles[i].set_fill_color(c);
}

void Graph_lib::MyHist::set_bar_label(std::string l, int i)
{
	labels[i].set_label(l);
}

void Graph_lib::MyHist::draw_lines() const
{
	for (int i = 0; i < rectangles.size(); ++i)
	{
		rectangles[i].draw_lines();
		if (labels[i].label() != "")
		{
			Line l(Point(rectangles[i].point(0).x, rectangles[i].point(0).y),
				Point(rectangles[i].point(0).x, labels[i].point(0).y));
			l.set_style(Line_style::dash);
			l.draw();
			labels[i].draw();
		}
	}
	Axis x(Axis::x, point(0), x_size, 0, x_label);
	x.label.move(3 * y_size / 4, 0);
	Axis y(Axis::y, point(0), y_size, 0, y_label);
	x.draw_lines();
	y.draw_lines();
}

double Graph_lib::MyHist::get_idata(int i)
{
	return data[i];
}

std::string Graph_lib::MyHist::set_x_label(std::string xl)
{
	x_label = xl;
	return x_label;
}

std::string Graph_lib::MyHist::set_y_label(std::string yl)
{
	y_label = yl;
	return y_label;
}
