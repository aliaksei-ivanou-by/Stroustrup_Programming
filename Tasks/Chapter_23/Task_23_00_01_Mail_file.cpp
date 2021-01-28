#ifndef TASK_23_00_01_STDAFX_H
#include "Task_23_00_01_stdafx.h"
#include "Task_23_00_01_Mail_file.h"
#endif

Message::Message(Line_iter p1, Line_iter p2) :
	first{ p1 },
	last{ p2 }
{}

Line_iter Message::begin() const
{
	return first;
}

Line_iter Message::end() const
{
	return last;
}

Mail_file::Mail_file(const std::string& n)
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

Mess_iter Mail_file::begin() const
{
	return m.begin();
}

Mess_iter Mail_file::end() const
{
	return m.end();
}

int is_prefix(const std::string& s, const std::string& p)
{
	int n = static_cast<int>(p.size());
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