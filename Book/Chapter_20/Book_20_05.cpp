double* find_highest(vector<double>& v)
{
	double h = -1;
	double* high = 0;
	for (int i = 0; i < v.size(); ++i)
	{
		if (h < v[i])
		{
			high = &v[i];
			h = v[i];
		}
	}
	return high;
}