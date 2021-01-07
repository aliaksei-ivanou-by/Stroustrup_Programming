template<class Iter, class T>
bool b2(Iter first, Iter last, const T& value)
{
	if (last < first)
	{
		throw Bad_sequence();
	}
	if (2 <= last - first)
	{
		for (Iter p = first + 1; p < last; ++p)
		{
			if (*p < *(p - 1))
			{
				throw Not_ordered();
			}
		}
	}
	return binary_search(first, last, value);
}

template<class Iter, class T>
bool binary_search(Iter first, Iter last, const T& value)
{
	if ("Test_on")
	{
		if ("Iter is an arbitrary action iterator")
		{
			// ...
			if (last < first)
			{
				throw Bad_sequence();
			}
		}
		// ...
		if (first != last)
		{
			Iter prev = first;
			for (Iter p = ++first; p != last; ++prev)
			{
				if (*p < *prev)
				{
					throw Not_ordered();
				}
			}
		}
	}
}