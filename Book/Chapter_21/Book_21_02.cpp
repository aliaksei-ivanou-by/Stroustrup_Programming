template<typename In, typename T>
In find1(In first, In last, const T& val)
{
	while (first != last && *first != val)
	{
		++first;
	}
	return first;
}

template<typename In, typename T>
In find2(In first, In last, const T& val)
{
	for (In p = first; p != last; ++p)
	{
		if (*p == val)
		{
			return p;
		}
	}
	return last;
}
