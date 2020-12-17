Text_iterator find_txt(Text_iterator first, Text_iterator last, const string& s)
{
	if (s.size() == 0)
	{
		return last;
	}
	char first_char = s[0];
	while (true)
	{
		auto p = find(first, last, first_char);
		if (p == last || match(p, last, s))
		{
			return p;
		}
		first = ++p;
	}
}

auto p = find_txt(my_doc.begin(), my_doc.end(), "secret\nhomestead");
if (p == my_doc.end())
{
	cout << "not found";
}
else
{
	// ...
}