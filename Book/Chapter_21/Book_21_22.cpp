int main()
{
	string from, to;
	cin >> from >> to;
	
	ifstream is(from);
	ifstream os(to);
	
	set<string> b(istream_iterator<string>{ is },
					istream_iterator<string>{});
	copy(b.begin(), b.end(), ostream_iterator<string>{ os, " " });
}