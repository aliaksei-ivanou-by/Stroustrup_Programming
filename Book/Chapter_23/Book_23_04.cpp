for (string s; cin >> s; )
{
	if (s.size() == 7 &&
		isalpha(s[0]) &&
		isalpha(s[1]) &&
		isdigit(s[2]) &&
		isdigit(s[3]) &&
		isdigit(s[4]) &&
		isdigit(s[5]) &&
		isdigit(s[6]))
	{
		cout << "Found " << s << '\n';
	}
}