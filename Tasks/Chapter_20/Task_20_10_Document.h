#ifndef TASK_20_10_DOCUMENT_H
#define TASK_20_10_DOCUMENT_H

#ifndef TASK_20_10_STDAFX_H
#include "Task_20_10_stdafx.h"
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
	unsigned long long int count_chars();
	unsigned long long int count_words_1();
	unsigned long long int count_words_2();
	unsigned long long int count_words_3(std::string& delimiter);
	Text_iterator find_text(const std::string& s);
	Text_iterator find_replace_text(const std::string& sFind, const std::string& sReplace);
	friend std::istream& operator>>(std::istream& inputStream, Document& d);
};

bool match(Text_iterator first, Text_iterator last, const std::string& s);
void print(const Text_iterator start, const Text_iterator end);

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

#endif