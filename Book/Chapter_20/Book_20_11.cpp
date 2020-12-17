template<typename Iter>
Iter high(Iter first, Iter last)
{
	Iter high = first;
	for (Iter p = first; p != last; ++p)
	{
		if (*high < *p)
		{
			high = p
		}
	}
	return high;
}

void f()
{
	list<int> lst;
	for (int x; cin >> x;)
	{
		lst.push_front(x);
	}
	list<int>::iterator p = high(lst.begin(); lst.end());
	coust << "Max is : " << *p << '\n';
}