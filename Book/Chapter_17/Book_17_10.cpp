struct Link
{
	string value;
	Link* prev;
	Link* succ;
	Link(const string& v, Link* p = nullptr, Link* s = nullptr)
	: value{ v },
	  prev{ p },
	  succ{ s }
};

Link* insert(Link* p, Link* n)
{
	if (n == nullptr)
	{
		return p;
	}
	if (p == nullptr)
	{
		return n;
	}
	n->succ = p;
	p->prev->succ = n;
	n->prev = p->prev;
	p->prev = n;
	return n;
}