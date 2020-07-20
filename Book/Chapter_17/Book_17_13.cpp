class Link
{
public:
	string value;
	Link(const string& v, Link* p = nullptr, Link* s = nullptr)
	: value{ v },
	  prev{ p },
	  succ{ s }
	Link* insert(Link* n);
	Link* add(Link* n);
	Link* erase();
	Link* find(const string& s);
	const Link* find(const string& s) const;
	Link* advance(int n) const;
	Link* next() const
	{
		return succ;
	}
	Link* previous() const
	{
		return prev;
	}
private:
	Link* prev;
	Link* succ;
};

Link* Link::insert(Link* n)
{
	if (n == nullptr)
	{
		return this;
	}
	if (this == nullptr)
	{
		return n;
	}
	n->succ = this;
	if (prev)
	{
		prev->succ = n;
	}
	n->prev = prev;
	prev = n;
	return n;
}