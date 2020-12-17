template<typename Iterator>
Iterator high(Iterator first, Iterator last)
{
	Iterator high = first;
	for (Iterator p = first; p != last; ++p)
	{
		if (*high < *p)
		{
			high = p;
		}
	}
	return high;
}