#ifndef TASK_20_10_STDAFX_H
#define TASK_20_10_STDAFX_H

#include <iostream>
#include <list>
#include <vector>
#include <fstream>
#include <algorithm>

#endif

using Line = std::vector<char>;

class Text_iterator
{
private:
	std::list<Line>::iterator ln;
	Line::iterator pos;
public:
	Text_iterator(std::list<Line>::iterator ll, Line::iterator pp):
		ln{ ll },
		pos{ pp }
	{}
	char& operator*()
	{
		return *pos;
	}
	Text_iterator& operator++()
	{
		++pos;
		if (pos == (*ln).end())
		{
			++ln;
			pos = (*ln).begin();
		}
		return *this;
	}
	bool operator==(const Text_iterator& other) const
	{
		return ln == other.ln && pos == other.pos;
	}
	bool operator!=(const Text_iterator& other) const
	{
		return !(*this == other);
	}
	Line& get_line() const
	{
		return *ln;
	}
	Line::iterator get_pos() const
	{
		return pos;
	}
};

bool match(Text_iterator first, Text_iterator last, const std::string& s)
{
	std::string::const_iterator p;
	for (p = s.begin();
		p != s.end() && first != last && *p == *first;
		++p, ++first)
	{}
	return p == s.end();
}

Text_iterator find_text(Text_iterator first, Text_iterator last, const std::string& s)
{
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
struct Document
{
	std::list<Line> line;
	Document()
	{
		line.push_back(Line());
	}
	Text_iterator begin()
	{
		return Text_iterator(line.begin(), (*line.begin()).begin());
	}
	Text_iterator end()
	{
		auto last = line.end();
		--last;
		return Text_iterator(last, (*last).end());
	}
};

void erase_line(Document& d, int n)
{
	if (n < 0 || d.line.size() - 1 < n)
	{
		return;
	}
	auto p = d.line.begin();
	advance(p, n);
	d.line.erase(p);
}

template<typename Iterator>
void advance(Iterator& p, int n)
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
			while (n < 0)
			{
				--p;
				++n;
			}
		}
	}
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

void print(Document& d, Text_iterator p)
{
	{
		for ( ; p != d.end(); ++p)
		{
			std::cout << *p;
		}
	}
}

void find_replace_text(Text_iterator first, Text_iterator last, const std::string& sFind, const std::string& sReplace)
{
	if (sFind == "")
	{
		return;
	}
	Text_iterator pFirst = find_text(first, last, sFind);
	if (pFirst == last)
	{
		return;
	}
	Line& line = pFirst.get_line();
	auto pLast = pFirst.get_pos();
	pLast = line.erase(pLast, pLast + sFind.size());
	for (auto i = sReplace.rbegin(); i != sReplace.rend(); ++i)
	{
		pLast = line.insert(pLast, *i);
	}
}

unsigned long long int count_chars(Document& d)
{
	unsigned long long int count = 0;
	for (const auto& i : d)
	{
		if (!isspace(i))
		{
			++count;
		}
	}
	return count;
}

unsigned long long int count_words_1(Document& d)
{
	unsigned long long int count = 0;
	bool isWord = false;
	for (const auto& i : d)
	{
		if (!isWord && isalpha(i)) // start of word
		{
			isWord = true;
		}
		if (isWord && isspace(i)) // finish of word
		{
			isWord = false;
			++count;
		}
	}
	return count;
}

unsigned long long int count_words_2(Document& d)
{
	unsigned long long int count = 0;
	bool isWord = false;
	for (const auto& i : d)
	{
		if (!isWord && isalpha(i)) // start of word
		{
			isWord = true;
		}
		if (isWord && !isalpha(i)) // finish of word
		{
			isWord = false;
			++count;
		}
	}
	return count;
}

unsigned long long int count_words_3(Document& d, std::string& delimiter)
{
	unsigned long long int count = 0;
	bool isWord = false;
	for (const auto& i : d)
	{
		if (!isWord && isalpha(i)) // start of word
		{
			isWord = true;
			++count;
		}
		if (isWord) // finish of word
		{
			for (const auto& j : delimiter)
			{
				if (i == j)
				{
					isWord = false;
					break;
				}
				if (i == j && i - 1 == '.')
				{
					isWord = false;
					break;
				}
				if (i == '\n' && i - 1 == '.')
				{
					isWord = false;
					break;
				}
			}
		}
	}
	return count;
}