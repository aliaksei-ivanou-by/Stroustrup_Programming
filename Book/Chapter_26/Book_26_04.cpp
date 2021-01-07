int do_dependent(int a, int& b)
{
	int val;
	cin >> val;
	vec[val] += 10;
	cout << a;
	b++;
	return b;
}