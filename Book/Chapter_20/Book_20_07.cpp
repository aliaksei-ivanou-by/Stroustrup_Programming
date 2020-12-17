double* get_from_jack(int* count);

vector<double*> get_from_jill();

void fct()
{
	int jack_count = 0;
	double* jack_data = get_from_jack(&jack_count);
	vector<double*> jill_data = get_from_jill();
	
	double* jack_high = high(jack_data, jack_data + jack_count);
	vector<double>& v = *jill_data;
	double* jill_high = high(&v[0], &v[0] + v.size());
	
	cout << "Max Jill : " << *jill_high 
		<< "; Max Jack : " << *jack_high;
	// ...
	delete[] jack_data;
	delete jill_data;
}