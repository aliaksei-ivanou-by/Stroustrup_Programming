template<typename In, typename Pred>
In find_if(In first, In last, Pred pred)
{
	while (first != last && !pred(*first))
	{
		++first;
	}
	return first;
}

bool odd(int x)
{
	return x % 2;
}

void f(vector<int>& v)
{
	auto p = find_if(v.begin(), v.end(), odd);
	if (p != v.end())
	{
		// ...
	}
}

bool larger_than_42(double x)
{
	return x > 42;
}

void f(list<double>& v)
{
	auto p = find_if(v.begin(), v.end(), larger_than_42);
	if (p != v.end())
	{
		// ...
	}
}