#ifndef TASK_16_10_MYFUNCTION_H
#define TASK_16_10_MYFUNCTION_H

#ifndef Task_16_10_STDAFX_H
#include "Task_16_10_stdafx.h"
#endif

class MyFunction : public Function
{
public:
	MyFunction(double (*f)(double), double r_min, double r_max, Point orig, int n_points = 100, double x_scale = 20, double y_scale = 20, double precision = 1);
	void update_points();
	void set_func(double (*func)(double));
	void set_range(double r_min, double r_max);
	void set_n_points(int n_points);
	void set_x_scale(double x_scale);
	void set_y_scale(double y_scale);
	void set_orig(Point orig);
	void set_precision(double precision);
private:
	double (*func)(double);
	double r_min;
	double r_max;
	Point orig;
	int n_points;
	double x_scale;
	double y_scale;
	double precision;
	void validate_range();
	void validate_n_points();
	void validate_x_scale();
	void validate_y_scale();
};

#endif