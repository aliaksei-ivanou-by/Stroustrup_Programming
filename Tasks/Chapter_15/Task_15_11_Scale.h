#ifndef TASK_15_11_SCALE_H
#define TASK_15_11_SCALE_H

#ifndef Task_15_11_STDAFX_H
#include "Task_15_11_stdafx.h"
#endif

class Scale
{
public:
	Scale(int b, int vb, double s);
	int operator()(int v) const;
private:
	int cbase;
	int vbase;
	double scale;
};

#endif