#ifndef TASK_15_02_STDAFX_H
#include "Task_15_02_stdafx.h"
#include "Task_15_02_MyFunction.h"
#endif

MyFunction::MyFunction(double (*f)(double), double r1, double r2, Point o, int n, double xsc, double ysc)
	: Function(f, r1, r2, o, n, xsc, ysc),
	func{ f },
	r_min{ r1 }, 
	r_max{ r2 }, 
	orig{ o }, 
	n_points{ n }, 
	x_scale{ xsc }, 
	y_scale{ ysc }
{
	set();
}

void MyFunction::set()
{
	double d = (r_max - r_min) / n_points;
	clear_points();

	double r_current = r_min;
	for (int i = 0; i <n_points; ++i)
	{
		add(Point(orig.x + r_current * x_scale,
			orig.y - func(r_current) * y_scale));
		r_current += d;
	}
}

void MyFunction::set_func(double (*f)(double))
{
	func = f;
	set();
}

void MyFunction::set_range(double r1, double r2)
{
	if (r2 <= r1)
	{
		error("Wrong range");
	}
	r_min = r1;
	r_max = r2;
	set();
}

void MyFunction::set_n_points(int n)
{
	if (n <= 0)
	{
		error("Wrong n points");
	}
	n_points = n;
	set();
}

void MyFunction::set_x_scale(double xsc)
{
	if (xsc == 0)
	{
		error("Wrong scale for X");
	}
	x_scale = xsc;
	set();
}

void MyFunction::set_y_scale(double ysc)
{
	if (ysc == 0)
	{
		error("Wrong scale for Y");
	}
	y_scale = ysc;
	set();
}

void MyFunction::set_orig(Point o)
{
	orig = o;
	set();
}
