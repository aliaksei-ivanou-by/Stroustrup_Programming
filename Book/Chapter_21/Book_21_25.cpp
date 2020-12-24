void test(vector<int>& v)
{
	sort(v.begin(), v.end())
}

void test(vector<int>& v)
{
	sort(v.begin(), v.begin() + v.size() / 2);
	sort(v.begin() + v.size() / 2, v.end());
}

void test(vector<int>& v)
{
	sort(v);
}

template<typename C>
void sort(C& c)
{
	std::sort(c.begin(), c.end());
}

template<typename C, typename V>
Iterator<C> find(C& c, Val v)
{
	return std::find(c.begin(), c.end(), v);
}