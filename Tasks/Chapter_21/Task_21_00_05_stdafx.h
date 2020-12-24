#ifndef TASK_21_00_05_STDAFX_H
#define TASK_21_00_05_STDAFX_H

#include <iostream>
#include <unordered_map>
#include<numeric>

#endif

double weighted_value(
	const std::pair<std::string, double>& a, 
	const std::pair<std::string, double>& b
)
{
	return a.second * b.second;
}