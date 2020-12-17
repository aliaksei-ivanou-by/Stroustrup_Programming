void print1(const vector<double>& v)
{
	for (int i = 0; i < v.size(); ++i)
	{
		cout << v[i] << '\n';
	}
}

void print2(const vector<double>& v, const list<double>& lst)
{
	for (double x : v)
	{
		cout << x << '\n';
	}
	
	for (double x : lst)
	{
		cout << x << '\n';
	}
}
