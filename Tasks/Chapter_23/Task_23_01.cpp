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
	std::string fileName("Task_23_01.txt");
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

	std::cout << "\nSenders: " << sender.size() << '\n';

	using senderConstIterator = std::multimap<std::string, const Message*>::const_iterator;

	std::string target_sender = "John Doe <jdoe@machine.example>";
	std::pair<senderConstIterator, senderConstIterator> pp = sender.equal_range(target_sender);

	std::cout << "Sender: " << target_sender << " has sent emails with subjects:\n";
	for (auto i = pp.first; i != pp.second; ++i)
	{
		std::string subject;

		if (find_subject(i->second, subject))
		{
			std::cout << subject << '\n';
		}
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