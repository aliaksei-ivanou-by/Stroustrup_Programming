#ifndef TASK_20_06_STDAFX_H
#include "Task_20_06_stdafx.h"
#include "Task_20_06_Document.h"
#endif

Text_iterator::Text_iterator(std::list<Line>::iterator ll, Line::iterator pp):
	ln{ ll },
	pos{ pp }
{}

char& Text_iterator::operator*()
{
	return *pos;
}

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

bool Text_iterator::operator==(const Text_iterator& other) const
{
	return ln == other.ln && pos == other.pos;
}

bool Text_iterator::operator!=(const Text_iterator& other) const
{
	return !(*this == other);
}

Line& Text_iterator::get_line() const
{
	return *ln;
}

Line::iterator Text_iterator::get_pos() const
{
	return pos;
}

bool match(Text_iterator first, Text_iterator last, const std::string& s)
{
	std::string::const_iterator p;
	for (p = s.begin();
		p != s.end() && first != last && *p == *first;
		++p, ++first)
	{}
	return p == s.end();
}

Text_iterator Document::find_text(const std::string& s)
{
	Text_iterator first = begin();
	Text_iterator last = end();
	if (s.size() == 0)
	{
		return last;
	}
	char first_char = s[0];
	while (true)
	{
		Text_iterator p = std::find(first, last, first_char);
		if (p == last || match(p, last, s))
		{
			return p;
		}
		first = ++p;
	}
}

Document::Document()
{
	line.push_back(Line());
}
const Text_iterator Document::begin()
{
	return Text_iterator(line.begin(), (*line.begin()).begin());
}

const Text_iterator Document::end()
{
	auto last = line.end();
	--last;
	return Text_iterator(last, (*last).end());
}

void Document::erase_line(int n)
{
	if (n < 0 || (*this).line.size() - 1 < n)
	{
		return;
	}
	auto p = (*this).line.begin();
	advance(p, n);
	(*this).line.erase(p);
}

std::istream& operator>>(std::istream& inputStream, Document& d)
{
	for (char ch; inputStream.get(ch); )
	{
		d.line.back().push_back(ch);
		if (ch == '\n')
		{
			d.line.push_back(Line());
		}
	}
	if (d.line.back().size())
	{
		d.line.push_back(Line());
	}
	return inputStream;
}

void print(const Text_iterator start, const Text_iterator end)
{
	for (auto i = start; i != end; ++i)
	{
		std::cout << *i;
	}
}

Text_iterator Document::find_replace_text(const std::string& sFind, const std::string& sReplace)
{
	if (sFind == "")
	{
		return end();
	}
	Text_iterator pFirst = find_text(sFind);
	if (pFirst == end())
	{
		return end();
	}
	Line& line = pFirst.get_line();
	auto pLast = pFirst.get_pos();
	pLast = line.erase(pLast, pLast + sFind.size());
	for (auto i = sReplace.rbegin(); i != sReplace.rend(); ++i)
	{
		pLast = line.insert(pLast, *i);
	}
	return pFirst;
}
