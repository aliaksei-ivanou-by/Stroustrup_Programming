void f1(list<double>& v, int x)
{
	auto p = find_if(v.begin(), v.end(), larger_than(31));
	if (p != v.end())
	{
		// ...
	}
	auto q = find_if(v.begin(), v.end(), larger_than(x));
	if (q != v.end())
	{
		// ...
	}
}

void f2(list<double>& v, int x)
{
	auto p = find_if(v.begin(), v.end(), 
			[](double a){ return a > 31; });
	if (p != v.end())
	{
		// ...
	}
	auto q = find_if(v.begin(), v.end(),
			[&](double a){ return a > x; });
	if (q != v.end())
	{
		// ...
	}
}