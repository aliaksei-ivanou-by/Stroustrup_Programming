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
	std::list<Line>::iterator get_line() const
	{
		return ln;
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
	while (n < 0)
	{
		--p;
		++n;
	}
}

struct Document
{
public:
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
		std::list<Line>::iterator last = line.end();
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
		if (n < 0 || (*this).line.size() - 1 <= n)
		{
			return;
		}
		std::list<Line>::iterator p = (*this).line.begin();
		advance(p, n);
		(*this).line.erase(p);
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
	void concat_lines(Text_iterator& pos)
	{
		auto current = pos.get_line();
		auto posLine = pos.get_pos();
		auto index = posLine - (*current).begin();
		auto next = current;
		++next;
		(*current).insert((*current).end(), (*next).begin(), (*next).end());
		pos = Text_iterator(current, (*current).begin() + index);
		auto listIterator = begin().get_line();
		int line = 0;
		while (listIterator != next)
		{
			++listIterator;
			++line;
		}
		erase_line(line);
	}
	unsigned long long int find_text_replace(Text_iterator first, Text_iterator last,
		const std::string& stringFind, const std::string& stringReplace)
	{
		unsigned long long int count = 0;
		if (stringFind == "")
		{
			return count;
		}
		Text_iterator pos = find_text(first, last, stringFind);
		while (pos != last)
		{
			auto stringFindIterator = stringFind.begin();
			auto stringReplaceIterator = stringReplace.begin();
			while (stringFindIterator != stringFind.end() &&
				stringReplaceIterator != stringReplace.end())
			{
				if (*stringFindIterator != *stringReplaceIterator)
				{
					*pos = *stringReplaceIterator;
					if (*stringFindIterator == '\n') // add next line to current
					{
						concat_lines(pos);
					}
					if (*stringReplaceIterator == '\n') // add text to the next line
					{
						auto current = pos.get_line();
						auto next = current;
						++next;
						(*next).insert((*next).begin(), pos.get_pos() + 1, (*current).end());
						(*current).erase(pos.get_pos() + 1, (*current).end());
					}
				}
				++pos;
				++stringFindIterator;
				++stringReplaceIterator;
			}
			while (stringFindIterator != stringFind.end())
			{
				if (*pos == '\n') // add next line to current
				{
					concat_lines(pos);
				}
				pos = Text_iterator(pos.get_line(),
					(*pos.get_line()).erase(pos.get_pos()));
				++stringFindIterator;
			}
			while (stringReplaceIterator != stringReplace.end())
			{
				pos = Text_iterator(pos.get_line(),
					(*pos.get_line()).insert(pos.get_pos(), *stringReplaceIterator));
				if (*stringReplaceIterator == '\n') // add text to the next line
				{
					auto current = pos.get_line();
					auto next = current;
					++next;
					(*next).insert((*next).begin(), pos.get_pos() + 1, (*current).end());
					(*current).erase(pos.get_pos() + 1, (*current).end());
				}
				++pos;
				++stringReplaceIterator;
			}
			++count;
			pos = find_text(pos, last, stringFind);
		}
		return count;
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