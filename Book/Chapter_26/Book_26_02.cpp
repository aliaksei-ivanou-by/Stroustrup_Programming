{ 27 7 { 1 2 3 5 8 13 21 } 0 }

struct Test
{
	string label;
	int val;
	vector<int> seq;
	bool res;
};
istream& operator>>(istream& is, Test& t);
int test_all(istream& is)
{
	int error_count = 0;
	for (Test t; is >> t; )
	{
		bool r = binary_search(t.seq.begin(),
								t.seq.end(),
								t.val);
		if (r != t.res)
		{
			cout << "Fail test " << t.label <<
					" binary_search: " <<
					t.seq.size() << " elements, val = " <<
					t.val << " -> " << t.res << '\n';
			++error_count;
		}
	}
	return error_count;
	
}
int main()
{
	int errors = test_all(ifstream("my_tests.txt"));
	cout << "Number of errors: " << errors << '\n';
}