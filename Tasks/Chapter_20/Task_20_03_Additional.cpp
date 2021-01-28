#ifndef TASK_20_03_STDAFX_H
#include "Task_20_03_stdafx.h"
#include "Task_20_03_Additional.h"
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

std::unique_ptr<double[]> get_from_jack(int* count)
{
	std::string fileName = "Task_20_03_jack.txt";
	std::ifstream fileStream(fileName.c_str());
	if (!fileStream)
	{
		throw std::runtime_error("Can't open file");
	}
	int size = 1;
	std::unique_ptr<double[]> oldVector = std::make_unique<double[]>(size);
	int i = 0;
	while (fileStream >> oldVector[i])
	{
		*count += 1;
		if (i + 1 == size)
		{
			std::unique_ptr<double[]> temp = std::make_unique<double[]>(size + 1);
			std::copy(oldVector.get(), oldVector.get() + size, temp.get());
			size += 1;
			oldVector = std::move(temp);
		}
		++i;
	}
	return oldVector;
}

std::unique_ptr<std::vector<double>> get_from_jill()
{
	std::string fileName = "Task_20_03_jill.txt";
	std::ifstream fileStream(fileName.c_str());
	if (!fileStream)
	{
		throw std::runtime_error("Can't open file");
	}
	std::unique_ptr<std::vector<double>> newVector = std::make_unique<std::vector<double>>();
	double number;
	while (fileStream >> number)
	{
		(*newVector).push_back(number);
	}
	return newVector;
}