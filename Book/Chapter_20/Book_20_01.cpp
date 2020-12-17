double* get_from_jack(int* count);

vector<double>* get_from_jill();

void fct()
{
	ubt jack_count = 0;
	double* jack_data = get_from_jack(&jack_count);
	vector<double>* jill_data = get_from_jill();
	// ...
	delete[] jack_data;
	delete jill_data;
}