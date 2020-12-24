void f()
{
	ostream_iterator<string> oo{ cout };
	*oo = "Hello, ";
	++oo;
	*oo = "World\n";

	istream_iterator<string> ii{ cin };
	string s1 = *ii;
	++ii;
	string s2 = *ii;
}

int main()
{
	string from, to;
	cin >> from >> to;
	
	ifstream is(from);
	ofstream os(to);
	
	istream_iterator<string> ii{ is };
	istream_iterator<string> eos;
	ostream_iterator<string> oo{ os, "\n" };
	
	vector<string> b(ii, eos);
	sort(b.begin(), b.end());
	copy(b.begin(), b.end(), oo);
	
	// vector<string> b(max_size());
	// copy(ii, eos, b.begin());
}