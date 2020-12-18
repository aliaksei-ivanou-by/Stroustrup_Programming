#ifndef TASK_20_07_STDAFX_H
#define TASK_20_07_STDAFX_H

#include <iostream>
#include <vector>
#include <fstream>

#endif

double* high(double* first, double* last)
{
	double h = -1;
	double* high = nullptr;
	for (double* p = first; p != last; ++p)
	{
		if (h < *p)
		{
			high = p;
			h = *p;
		}
	}
	return high;
}

double* get_from_jack(int* count)
{
	std::string fileName = "Task_20_02_jack.txt";
	std::ifstream fileStream(fileName.c_str());
	if (!fileStream)
	{
		throw("Can't open file");
	}
	std::vector<double> oldVector;
	double number;
	while (fileStream >> number)
	{
		oldVector.push_back(number);
	}

	*count = oldVector.size();
	double* newVector = new double[*count];
	for (size_t i = 0; i < oldVector.size(); ++i)
	{
		newVector[i] = oldVector[i];
	}
	return newVector;
}

std::vector<double>* get_from_jill()
{
	std::string fileName = "Task_20_02_jill.txt";
	std::ifstream fileStream(fileName.c_str());
	if (!fileStream)
	{
		throw("Can't open file");
	}
	std::vector<double>* newVector = new std::vector<double>;
	double number;
	while (fileStream >> number)
	{
		(*newVector).push_back(number);
	}
	return newVector;
}