#ifndef TASK_20_09_DOCUMENT_H
#define TASK_20_09_DOCUMENT_H

#ifndef TASK_20_09_STDAFX_H
#include "Task_20_09_stdafx.h"
#endif

using Line = std::vector<char>;

class Text_iterator
{
private:
	std::list<Line>::iterator ln;
	Line::iterator pos;
public:
	Text_iterator(std::list<Line>::iterator ll, Line::iterator pp);
	char& operator*();
	Text_iterator& operator++();
	bool operator==(const Text_iterator& other) const;
	bool operator!=(const Text_iterator& other) const;
	Line& get_line() const;
	Line::iterator get_pos() const;
};

struct Document
{
	std::list<Line> line;
	Document();
	const Text_iterator begin();
	const Text_iterator end();
	void erase_line(int n);
	unsigned long long count_chars();
	unsigned long long int count_words_1();
	unsigned long long int count_words_2();
	friend std::istream& operator>>(std::istream& inputStream, Document& d);
};

bool match(Text_iterator first, Text_iterator last, const std::string& s);
Text_iterator find_text(Text_iterator first, Text_iterator last, const std::string& s);
void find_replace_text(Text_iterator first, Text_iterator last, const std::string& sFind, const std::string& sReplace);
void print(const Text_iterator start, const Text_iterator end);

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

#endif