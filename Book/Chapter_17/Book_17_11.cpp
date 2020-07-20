Link* add(Link* p, Link* n)
{
	// ...
}

Link* erase(Link* p)
{
	if (p == nullptr)
	{
		return nullptr;
	}
	if (p->succ)
	{
		p->succ->prev = p->prev;
	}
	if (p->prev)
	{
		p->prev->succ = p->succ;
	}
	return p->succ;
}

Link* find(Link* p, const string& s)
{
	while (p)
	{
		if (p->value == s)
		{
			return p;
		}
		p = p->succ;
	}
	return nullptr;
}

Link* advance(Link* p, int n)
{
	if (p == nullptr)
	{
		return nullptr;
	}
	if (0 < n)
	{
		while (n--)
		{
			if (p->succ == nullptr)
			{
				return nullptr;
			}
			p = p->succ;
		}
	}
	else
	{
		if (n < 0)
		{
			while (n++)
			{
				if (p->prev == nullptr)
				{
					return nullptr;
				}
				p = p->prev;
			}
		}
	}
	return p;
}