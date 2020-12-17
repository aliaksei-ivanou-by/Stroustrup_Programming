struct Document
{
	list<Line> line;
	Text_iterator begin()
	{
		return Text_iterator(line.begin(), (*line.begin()).begin());
	}
	Text_iterator end()
	{
		return (line.end(), (*line.end()).end());
	}