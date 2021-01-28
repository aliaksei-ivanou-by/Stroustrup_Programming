#ifndef TASK_21_00_05_STDAFX_H
#include "Task_21_00_05_stdafx.h"
#include "Task_21_00_05_weighted_value.h"
#endif

double weighted_value(const std::pair<std::string, double>& a, const std::pair<std::string, double>& b)
{
	return a.second * b.second;
}