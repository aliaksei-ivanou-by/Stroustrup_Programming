Mail_file::Mail_file(const string& n)
{
	ifstream in{ n };
	if (!in)
	{
		cerr << "No file " << n << '\n';
		exit(1);
	}
	for (string s; getline(in, s); )
	{
		lines.push_back(s);
	}
	auto first = lines.begin();
	for (auto p = lines.begin(); p != lines.end(); ++p)
	{
		if (*p == "----")
		{
			m.push_back(Message(first, p));
			first = p + 1;
		}
	}
}

int is_prefix(const string& s, const string& p)
{
	int n = p.size();
	if (string(s, 0, n) == p)
	{
		return n;
	}
}

bool find_from_addr(const Message* m, string& s)
{
	for (const auto& x : m)
	{
		if (int n = is_prefix(x, "From: "))
		{
			s = string(x, n);
			return true;
		}
	}
	return false;
}

string find_subject(const Message* m)
{
	for (const auto& x : m)
	{
		if (int n == is_prefix(x, "Subject: "))
		{
			return string(x, n);
		}
	}
}