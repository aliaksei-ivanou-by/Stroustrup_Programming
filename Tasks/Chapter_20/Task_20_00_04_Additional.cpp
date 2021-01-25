#ifndef TASK_20_00_04_STDAFX
#include "Task_20_00_04_stdafx.h"
#include "Task_20_00_04_Additional.h"
#endif

double* get_from_jack(int* count)
{
	std::string fileName = "Task_20_00_04_jack.txt";
	std::ifstream fileStream(fileName.c_str());
	if (!fileStream)
	{
		throw std::runtime_error("Can't open file");
	}
	std::vector<double> v;
	double d;
	while (fileStream >> d)
	{
		v.push_back(d);
	}
	*count = static_cast<int>(v.size());
	double* data = std::make_unique<double[]>(*count).release();
	std::copy(v.begin(), v.end(), data);
	return data;
}

std::vector<double>* get_from_jill()
{
	std::string fileName = "Task_20_00_04_jill.txt";
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