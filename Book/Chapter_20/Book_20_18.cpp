using Line = vector<char>;

struct Document
{
	list<Line> line;
	Document()
	{
		line.push_back(Line{});
	}
};

istream& operator>>(istream& is, Document& d)
{
	for (char ch; is.get(ch))
	{
		d.line.back().push_back(ch);
		if (ch == '\n')
		{
			d.line.push_back(Line{});
		}
	}
	if (d.line.back().size())
	{
		d.line.push_back(Line{});
	}
	return is;
}