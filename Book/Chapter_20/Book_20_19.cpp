class Text_iterator
{
private:
	list<Line>::iterator ln;
	Line::iterator pos;
public:
	Text_iterator(list<Line>::iterator ll, Line::iterator pp):
		ln{ ll },
		pos{ pp }
	{}
	char& operator*()
	{
		return *pos;
	}
	Text_iterator operator++();
	bool operator==(conts Text_iterator& other) const
	{
		return ln == other.ln && pos == other.pos;
	}
	bool operator!=(const Text_iterator& other) const
	{
		return !(*this == other);
	}
};

Text_iterator& Text_iterator::operator++()
{
	++pos;
	if (pos == (*ln).end())
	{
		++ln;
		pos = (*ln).begin();
	}
	return *this;
}