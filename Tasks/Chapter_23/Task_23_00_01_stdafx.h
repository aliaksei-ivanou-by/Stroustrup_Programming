#ifndef TASK_23_00_01_STDAFX_H
#define TASK_23_00_01_STDAFX_H

#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <iostream>

#endif

using Line_iter = std::vector<std::string>::const_iterator;

class Message
{
private:
	Line_iter first;
	Line_iter last;
public:
	Message(Line_iter p1, Line_iter p2) :
		first{ p1 },
		last{ p2 }
	{}
	Line_iter begin() const
	{
		return first;
	}
	Line_iter end() const
	{
		return last;
	}
};

typedef std::vector<Message>::const_iterator Mess_iter;

bool find_message_end(Line_iter line);
int is_prefix(const std::string& s, const std::string& p);
std::string find_subject(const Message* m);
bool find_from_addr(const Message* m, std::string& s);

class Mail_file
{
private:
	std::string name;
	std::vector<std::string> lines;
	std::vector<Message> m;
public:
	Mail_file(const std::string& n)
	{
		std::ifstream in(n);
		if (!in)
		{
			std::cerr << "No file\n";
			exit(1);
		}
		for (std::string s; getline(in, s); )
		{
			lines.push_back(s);
		}

		bool messageNew = false;

		auto first = lines.begin();
		for (auto p = lines.begin(); p != lines.end(); ++p)
		{
			if (is_prefix(*p, "From: "))
			{
				if (messageNew)
				{
					return;
				}
				messageNew = true;
			}
			if (find_message_end(p))
			{
				while (find_message_end(p))
				{
					if (find_message_end(p) == find_message_end(p - 1))
					{
						return;
					}
					++p;
				}
				if (messageNew)
				{
					messageNew = false;
				}
				m.push_back(Message(first, p));
				first = p + 1;
				std::cout << "Message!\n";
			}
		}
	}
	Mess_iter begin() const
	{
		return m.begin();
	}
	Mess_iter end() const
	{
		return m.end();
	}
};

int is_prefix(const std::string& s, const std::string& p)
{
	int n = p.size();
	if (std::string(s, 0, n) == p)
	{
		return n;
	}
	return 0;
}

bool find_from_addr(const Message* m, std::string& s)
{
	for (Line_iter p = m->begin(); p != m->end(); ++p)
	{
		int n = 0;
		if (int n = is_prefix(*p, "From: "))
		{
			s = std::string(*p, n);
			return true;
		}
	}
	return false;
}

std::string find_subject(const Message* m)
{
	for (Line_iter p = m->begin(); p != m->end(); ++p)
	{
		int n = 0;
		if (int n = is_prefix(*p, "Subject: "))
		{
			return std::string(*p, n);
		}
	}
	return "";
}

bool find_message_end(Line_iter line)
{
	return *line == "----";
}