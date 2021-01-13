#ifndef TASK_23_04_STDAFX_H
#define TASK_23_04_STDAFX_H

#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <iostream>
#include <regex>

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
bool is_prefix(const std::string& s, const std::string& p, std::string& result);
bool find_subject(const Message* m, std::string& subject);
bool find_from_addr(const Message* m, std::string& s);

class Mail_file
{
private:
	std::string name;
	std::vector<std::string> lines;
	std::vector<Message> m;
public:
	Mail_file(const std::string& fileName)
	{
		std::ifstream in(fileName);
		if (!in)
		{
			std::cerr << "No file\n";
			exit(1);
		}
		for (std::string s; getline(in, s); )
		{
			lines.push_back(s);
		}

		auto first = lines.begin();
		for (auto p = lines.begin(); p != lines.end(); ++p)
		{
			if (find_message_end(p))
			{
				m.push_back(Message(first, p));
				first = p + 1;
			}
		}
		std::cout << "Messages: " << m.size();
		std::cout << "\nLines: " << lines.size();
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

bool is_prefix(const std::string& s, const std::string& p, std::string& result)
{
	std::regex reg{ "^" + p + "(.+)$" };
	std::smatch matches;
	if (std::regex_match(s, matches, reg))
	{
		result = matches[1];
		return true;
	}
	return false;
}

bool find_from_addr(const Message* m, std::string& s)
{
	for (Line_iter p = m->begin(); p != m->end(); ++p)
	{
		int n = 0;
		if (is_prefix(*p, "From: ", s))
		{
			return true;
		}
	}
	return false;
}

bool find_subject(const Message* m, std::string& subject)
{
	for (Line_iter p = m->begin(); p != m->end(); ++p)
	{
		int n = 0;
		if (is_prefix(*p, "Subject: ", subject))
		{
			return true;
		}
	}
	return false;
}

bool find_message_end(Line_iter line)
{
	return *line == "----";
}