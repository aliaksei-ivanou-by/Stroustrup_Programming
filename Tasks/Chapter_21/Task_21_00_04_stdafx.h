#ifndef TASK_21_00_04_STDAFX_H
#define TASK_21_00_04_STDAFX_H

#include <iostream>
#include <map>
#include<numeric>

#endif

double weighted_value(
	const std::pair<std::string, double>& a, 
	const std::pair<std::string, double>& b
)
{
	return a.second * b.second;
}