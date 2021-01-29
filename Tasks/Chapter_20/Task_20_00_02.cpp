double* high(double* first, double* last)
{
	double* high = first;
	for (double* p = first; p != last; ++p)
	{
		if (*high < *p)
		{
			high = p;
		}
	}
	return high;
}
double* jack_high = high(jack_data, jack_data + jack_count);
vector<double>& v = *jill_data;
double* jill_high = high(&v[0], &v[0] + v.size());