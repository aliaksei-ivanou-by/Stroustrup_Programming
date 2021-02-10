#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <iostream>
#include <regex>
#include "Task_23_Mail_file.h"

int main()
try
{
	Mail_file mailFile{ "Task_23_00_01.txt" };

	std::multimap<std::string, const Message*> sender;

	for (const auto& i : mailFile)
	{
		std::string subject;
		if (find_from_addr(&i, subject))
		{
			sender.insert(std::make_pair(subject, &i));
		}
	}
	auto p = sender.equal_range("John Doe <jdoe@machine.example>");
	for (auto i = p.first; i != p.second; ++i)
	{
		std::cout << find_subject(i->second) << '\n';
	}
}
catch (const std::exception& e)
{
	std::cout << "Exception occured: " << e.what() << '\n';
	return 1;
}
catch (...)
{
	return 2;
}