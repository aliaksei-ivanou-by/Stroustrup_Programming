void erase_line(Document& d, int n)
{
	if (n < 0 || d.line.size() - 1 <= n)
	{
		return;
	}
	auto p = d.line.begin();
	advance(p, n);
	d.line.erase(p);
}

template<typename Iter>
void advance(Iter& p, int n)
{
	if (n > 0)
	{
		while (n > 0)
		{
			++p;
			--n;
		}
	}
	else
	{
		if (n < 0)
		{
			--p;
			++n;
		}
	}
}