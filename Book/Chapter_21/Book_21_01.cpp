template<typename In, typename T>
In find(In first, In last, const T& val)
{
	while (first != last && *first != val)
	{
		++first;
	}
	return first;
}

void f(vector<int>& v, int x)
{
	auto p = find(v.begin(), v.end(), x);
	if (p != v.end())
	{
		// ...
	}
	else
	{
		// ...
	}
}