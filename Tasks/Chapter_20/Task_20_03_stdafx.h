#ifndef TASK_20_03_STDAFX_H
#define TASK_20_03_STDAFX_H

#include <iostream>
#include <vector>
#include <fstream>
#include <limits>

#endif

double* high(double* first, double* last)
{
	double h = DBL_MIN;
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

double* high(double* myArray, size_t size)
{
	if (size == 0)
	{
		return nullptr;
	}
	double* high = &myArray[0];
	for (size_t i = 0; i < size; ++i)
	{
		if (myArray[i] > *high)
		{
			high = &myArray[i];
		}
	}
	return high;
}

double* high(std::vector<double>& myVector)
{
	if (myVector.size() == 0)
	{
		return nullptr;
	}
	double* high = &myVector[0];
	for (size_t i = 0; i < myVector.size(); ++i)
	{
		if (myVector[i] > *high)
		{
			high = &myVector[i];
		}
	}
	return high;
}

double* get_from_jack(int* count)
{
	std::string fileName = "Task_20_03_jack.txt";
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
	std::string fileName = "Task_20_03_jill.txt";
	std::ifstream fileStream(fileName.c_str());
	if (!fileStream)
	{
		throw("Can't open file");
	}
	std::vector<double>* newVector = std::make_unique<std::vector<double>>().release();
	double number;
	while (fileStream >> number)
	{
		(*newVector).push_back(number);
	}
	return newVector;
}