double* get_from_jack(int* count);

vector<double>* get_from_jill();

void fct()
{
	ubt jack_count = 0;
	double* jack_data = get_from_jack(&jack_count);
	vector<double>* jill_data = get_from_jill();
	// ...
	double h = -1;
	double* jack_high;
	double* jill_high;
	for (int i = 0; i < jack_count; ++i)
	{
		if (h < jack_data[i])
		{
			jack_high = &jack_data[i];
			h = jack_data[i];
		}
	}
	h = -1;
	if (h < (*jill_data)[i])
	{
		jill_data = &(*jill_data)[i];
		h = (*jill_data)[i];
	}
	cout << "Max Jill : " << *jill_high
		<< "; Max Jack : " << *jack_high;
	// ...
	delete[] jack_data;
	delete jill_data;
}