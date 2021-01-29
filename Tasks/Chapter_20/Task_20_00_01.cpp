double* high(double* first, double* last)
{
	double h = -1;
	double* high;
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
double* jack_high = high(jack_data, jack_data + jack_count);
vector<double>& v = *jill_data;
double* jill_high = high(&v[0], &v[0] + v.size());