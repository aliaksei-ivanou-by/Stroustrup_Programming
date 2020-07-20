#ifndef TASK_15_02_MYFUNCTION_H
#define TASK_15_02_MYFUNCTION_H

#ifndef Task_15_02_STDAFX_H
#include "Task_15_02_stdafx.h"
#endif

class MyFunction : public Function
{
public:
	MyFunction(double (*f)(double), double r_min, double r_max, Point orig, int n_points = 100, double x_scale = 20, double y_scale = 20);
	void set();
	void set_func(double (*func)(double));
	void set_range(double r_min, double r_max);
	void set_n_points(int n_points);
	void set_x_scale(double x_scale);
	void set_y_scale(double y_scale);
	void set_orig(Point orig);
private:
	double (*func)(double);
	double r_min;
	double r_max;
	Point orig;
	int n_points;
	double x_scale;
	double y_scale;
};

#endif