#pragma once
#include <iostream>
#include <vector>
#include <list>

using Line = std::vector<char>;

class Text_iterator
{
private:
	std::list<Line>::iterator ln;
	Line::iterator pos;
public:
	Text_iterator(std::list<Line>::iterator ll, Line::iterator pp) :
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
	{
	}
	return p == s.end();
}

struct Document
{
	std::list<Line> line;
	Document()
	{
		line.push_back(Line());
	}
	const Text_iterator begin()
	{
		return Text_iterator(line.begin(), (*line.begin()).begin());
	}
	const Text_iterator end()
	{
		auto last = line.end();
		--last;
		return Text_iterator(last, (*last).end());
	}
	void print()
	{
		for (auto i = begin(); i != end(); ++i)
		{
			std::cout << *i;
		}
	}
	void erase_line(int n)
	{
		if (n < 0 || (*this).line.size() - 1 < n)
		{
			return;
		}
		auto p = (*this).line.begin();
		advance(p, n);
		(*this).line.erase(p);
	}
	unsigned long long int count_chars()
	{
		unsigned long long int count = 0;
		for (const auto& i : *this)
		{
			if (!isspace(i))
			{
				++count;
			}
		}
		return count;
	}
	unsigned long long int count_words_1()
	{
		unsigned long long int count = 0;
		bool isWord = false;
		for (const auto& i : *this)
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
	unsigned long long int count_words_2()
	{
		unsigned long long int count = 0;
		bool isWord = false;
		for (const auto& i : *this)
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
	unsigned long long int count_words_3(std::string& delimiter)
	{
		unsigned long long int count = 0;
		bool isWord = false;
		for (const auto& i : *this)
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
					if (i == j && ispunct(i - 1))
					{
						isWord = false;
						break;
					}
					if (i == '\n' && ispunct(i - 1))
					{
						isWord = false;
						break;
					}
					if (i == '\n')
					{
						isWord = false;
						break;
					}
				}
			}
		}
		return count;
	}
	Text_iterator find_text(const std::string& s)
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
	Text_iterator find_replace_text(const std::string& sFind, const std::string& sReplace)
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
	friend std::istream& operator>>(std::istream& inputStream, Document& d)
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
};

void print(const Text_iterator start, const Text_iterator end)
{
	for (auto i = start; i != end; ++i)
	{
		std::cout << *i;
	}
}

template<typename Iterator>
void advance(Iterator& p, int n)
{
	while (n > 0)
	{
		++p;
		--n;
	}
	if (n < 0)
	{
		while (n < 0)
		{
			--p;
			++n;
		}
	}
}