#ifndef TASK_20_04_STDAFX
#include "Task_20_04_stdafx.h"
#include "Task_20_04_Additional.h"
#endif

double* get_from_jack(int* count)
{
	std::string fileName = "Task_20_04_jack.txt";
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
	return oldVector.release();
}

std::vector<double>* get_from_jill()
{
	std::string fileName = "Task_20_04_jill.txt";
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
	return newVector.release();
}

void fct()
{
	int jack_count = 0;
	double* jack_data = get_from_jack(&jack_count);
	std::vector<double>* jill_data = get_from_jill();

	double* jack_high = high(jack_data, jack_data + jack_count);
	std::vector<double>& v = *jill_data;
	double* jill_high = high(&v[0], &v[0] + v.size());

	std::cout << "Max Jill: " << *jill_high << "; Max Jack: " << *jack_high;

	delete[] jack_data;
	delete jill_data;
}