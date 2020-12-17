template<typename T>
void user(vector<T>& v, list<T>& lst)
{
	for (auto p = v.begin(); p != v.end(); ++p)
	{
		coust << *p << '\n';
	}
	auto q = find(lst.begin(), lst.end(), T{42});
}