#ifndef TASK_23_02_STDAFX_H
#include "Task_23_02_stdafx.h"
#endif

int main()
try
{
	std::string fileName("Task_23_02.txt");
	Mail_file mailFile(fileName);
	std::multimap<std::string, const Message*> subject;

	for (auto i = mailFile.begin(); i != mailFile.end(); ++i)
	{
		const Message& message = *i;
		std::string s;

		if (find_subject(&message, s))
		{
			subject.insert(std::make_pair(s, &message));
		}
	}

	std::cout << "\nSubjects: " << subject.size() << '\n';

	using senderConstIterator = std::multimap<std::string, const Message*>::const_iterator;

	std::string target_subject = "Saying Hello";
	std::pair<senderConstIterator, senderConstIterator> pp = subject.equal_range(target_subject);

	std::cout << "Emails with subject: '" << target_subject << "' have messages:\n";
	for (auto i = pp.first; i != pp.second; ++i)
	{
		std::cout << *i->second->begin() << '\n';
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