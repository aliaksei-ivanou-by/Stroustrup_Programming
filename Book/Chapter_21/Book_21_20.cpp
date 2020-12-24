template<typename In, typename Out>
Out copy(In first, In last, Out res)
{
	while (first != last)
	{
		*res = *first;
		++res;
		++first;
	}
	return res;
}

void f(vector<double>& vd, list<int>& li)
{
	if (vd.size() < li.size())
	{
		error("Wrong size");
	}
	copy(li.begin(), li.end(), vd.begin());
}