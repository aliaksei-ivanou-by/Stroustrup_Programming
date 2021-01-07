void make_test(const string& lab, int n, in base, int spread)
{
	cout << " { " << lab << ' ' << n <<" { ";
	vector<int> v;
	int elem = base;
	for (int i = 0; i < n; ++i)
	{
		elem += randint(spread);
		v.push_back(elem);
	}
	int val = base + randint(elem - base);
	bool found = false;
	for (int i = 0; i < n; ++i)
	{
		if (v[i] == val)
		{
			found = true;
		}
		cout << v[i] << ' ';
	}
	cout << " } " << found << " }\n";
}

int no_of_tests = randint(100);
for (int i = 0; i < no_of_tests; ++i)
{
	string lab = "rand_test_";
	make_test(
			lab + to_string(i),
			randint(500),
			0,
			randint(50));
}