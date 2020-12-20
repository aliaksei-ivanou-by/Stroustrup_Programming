#ifndef TASK_20_03_STDAFX_H
#include "Task_20_03_stdafx.h"
#endif

int main()
try
{
	// Jack Data
	int jack_count = 0;
	double* jack_data = get_from_jack(&jack_count);

	double* jack_high_ptr = high(jack_data, jack_data + jack_count);

	double* jack_high_arr = high(jack_data, jack_count);

	std::vector<double> jack_vec;
	for (int i = 0; i < jack_count; ++i)
	{
		jack_vec.push_back(jack_data[i]);
	}
	double* jack_high_vec = high(jack_vec);

	// Jill Data
	std::vector<double>* jill_data = get_from_jill();

	std::vector<double>& jill_vec = *jill_data;
	double* jill_high_ptr = high(&jill_vec[0], &jill_vec[0] + jill_vec.size());

	double* jill_arr = std::make_unique<double[]>((*jill_data).size()).release();
	for (int i = 0; i < (*jill_data).size(); ++i)
	{
		jill_arr[i] = (*jill_data)[i];
	}
	double* jill_high_arr = high(jill_arr, (*jill_data).size());

	double* jill_high_vec = high(*jill_data);

	// Print
	std::cout << "Max Jill: " << *jill_high_ptr << "; Max Jack: " << *jack_high_ptr << '\n';
	std::cout << "Max Jill: " << *jill_high_arr << "; Max Jack: " << *jack_high_arr << '\n';
	std::cout << "Max Jill: " << *jill_high_vec << "; Max Jack: " << *jack_high_vec << '\n';
}
catch (const std::exception& e)
{
	std::cout << "Exception occured: " << e.what() << '\n';
	return 1;
}
catch (...)
{
	return 2;
}