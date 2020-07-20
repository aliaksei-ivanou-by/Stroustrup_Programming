#ifndef TASK_16_10_STDAFX_H
#include "Task_16_10_stdafx.h"
#include "Task_16_10_MyFunction.h"
#endif

MyFunction::MyFunction(double (*f)(double), double r1, double r2, Point o, int n, double xsc, double ysc, double pr)
	: Function(f, r1, r2, o, n, xsc, ysc),
	func{ f },
	r_min{ r1 },
	r_max{ r2 },
	orig{ o },
	n_points{ n },
	x_scale{ xsc },
	y_scale{ ysc },
	precision{ pr }
{
	validate_range();
	validate_n_points();
	validate_x_scale();
	validate_y_scale();
	update_points();
}

void MyFunction::update_points()
{
	double d = (r_max - r_min) / n_points;
	clear_points();

	double r_current = r_min;
	for (int i = 0; i < n_points; ++i)
	{
		add(Point(orig.x + static_cast<int>(static_cast<int>(r_current * x_scale) / precision) * precision,
			orig.y - static_cast<int>(static_cast<int>(func(r_current) * y_scale) / precision) * precision));
		r_current += d;
	}
}

void MyFunction::set_func(double (*f)(double))
{
	func = f;
	update_points();
}

void MyFunction::set_range(double r1, double r2)
{
	r_min = r1;
	r_max = r2;
	validate_range();
	update_points();
}

void MyFunction::set_n_points(int n)
{
	n_points = n;
	validate_n_points();
	update_points();
}

void MyFunction::set_x_scale(double xsc)
{
	x_scale = xsc;
	validate_x_scale();
	update_points();
}

void MyFunction::set_y_scale(double ysc)
{
	y_scale = ysc;
	validate_y_scale();
	update_points();
}

void MyFunction::set_orig(Point o)
{
	orig = o;
	update_points();
}

void MyFunction::set_precision(double pr)
{
	precision = pr;
	update_points();
}

void MyFunction::validate_range()
{
	if (r_max <= r_min)
	{
		error("Wrong range");
	}
}

void MyFunction::validate_n_points()
{
	if (n_points <= 0)
	{
		error("Wrong n points");
	}
}

void MyFunction::validate_x_scale()
{
	if (x_scale == 0)
	{
		error("Wrong scale for X");
	}
}

void MyFunction::validate_y_scale()
{
	if (y_scale == 0)
	{
		error("Wrong scale for Y");
	}
}
