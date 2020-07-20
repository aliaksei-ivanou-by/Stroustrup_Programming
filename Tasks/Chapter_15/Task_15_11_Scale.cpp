#ifndef TASK_15_11_STDAFX_H
#include "Task_15_11_stdafx.h"
#include "Task_15_11_Scale.h"
#endif

Scale::Scale(int b, int vb, double s)
	: cbase{ b }, vbase{ vb }, scale{ s }
{
}

int Scale::operator()(int v) const
{
	return cbase + (v - vbase) * scale;
}
