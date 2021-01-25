#ifndef TASK_20_02_STDAFX
#include "Task_20_02_stdafx.h"
#include "Task_20_02_Additional.h"
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
		throw std::runtime_error("Can't open file");
	}
	std::vector<double> oldVector;
	double number;
	while (fileStream >> number)
	{
		oldVector.push_back(number);
	}
	*count = static_cast<int>(oldVector.size());
	double* newVector = std::make_unique<double[]>(*count).release();
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
		throw std::runtime_error("Can't open file");
	}
	std::vector<double>* newVector = std::make_unique<std::vector<double>>().release();
	double number;
	while (fileStream >> number)
	{
		(*newVector).push_back(number);
	}
	return newVector;
}