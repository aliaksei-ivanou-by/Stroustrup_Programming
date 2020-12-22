double v_val;

bool larger_than_v(double x)
{
	return x > val;
}

void f(list<double>& v, int x)
{
	v_val = 31;
	auto p = find_if(v.begin(), v.end(), larger_than_v);
	if (p != v.end())
	{
		// ...
	}
	v_val = x;
	auto q = find_if(v.begin(), v.end(), larger_than_v);
	if (q != v.end())
	{
		// ...
	}
}