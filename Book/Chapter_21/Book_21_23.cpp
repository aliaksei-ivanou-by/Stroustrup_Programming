template<typename In, typename Out, typename Pred>
Out copy_if(In first, In last, Out res, Pre p)
{
	while (first != last)
	{
		if (p(*first)
		{
			*res++ = *first;
		}
		++first;
	}
	return res;
}

void f(const vector<int>& v)
{
	vector<int> v2(v.size());
	copy_if(v.begin(), v.end(), v2.begin(), larger_than(6));
}