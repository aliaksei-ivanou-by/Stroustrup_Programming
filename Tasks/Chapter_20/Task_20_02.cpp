#ifndef TASK_20_02_STDAFX_H
#include "Task_20_02_stdafx.h"
#endif

int main()
try
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
catch (const std::exception& e)
{
	std::cout << "Exception occured: " << e.what() << '\n';
	return 1;
}
catch (...)
{
	return 2;
}