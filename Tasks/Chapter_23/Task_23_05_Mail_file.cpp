#ifndef TASK_23_05_STDAFX
#include "Task_23_05_stdafx.h"
#include "Task_23_05_Mail_file.h"
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

Mail_file::Mail_file(const std::string& fileName)
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

Mess_iter Mail_file::begin() const
{
	return m.begin();
}

Mess_iter Mail_file::end() const
{
	return m.end();
}

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

void test_map(int n)
{
	std::map<int, int> m;
	for (int i = 0; i < n; ++i)
	{
		m.insert(std::make_pair(i, i));
	}
}

void testMap()
{
	auto timeVectorStart = std::chrono::system_clock::now();
	std::string fileName("Task_23_05.txt");
	Mail_file mailFile(fileName);
	std::multimap<std::string, const Message*> sender;

	for (auto i = mailFile.begin(); i != mailFile.end(); ++i)
	{
		const Message& message = *i;
		std::string s;

		if (find_from_addr(&message, s))
		{
			sender.insert(std::make_pair(s, &message));
		}
	}
	auto timeVectorFinish = std::chrono::system_clock::now();
	std::cout << "\nTime for map is\t" <<
		std::chrono::duration_cast<std::chrono::milliseconds>(timeVectorFinish - timeVectorStart).count() << "ms";
	std::cout << "\n";
}

void testUnorderedMap()
{
	auto timeVectorStart = std::chrono::system_clock::now();
	std::string fileName("Task_23_05.txt");
	Mail_file mailFile(fileName);
	std::unordered_multimap<std::string, const Message*> sender;

	for (auto i = mailFile.begin(); i != mailFile.end(); ++i)
	{
		const Message& message = *i;
		std::string s;

		if (find_from_addr(&message, s))
		{
			sender.insert(std::make_pair(s, &message));
		}
	}
	auto timeVectorFinish = std::chrono::system_clock::now();
	std::cout << "\nTime for unordered_multimap is\t" <<
		std::chrono::duration_cast<std::chrono::milliseconds>(timeVectorFinish - timeVectorStart).count() << "ms";
	std::cout << "\n";
}