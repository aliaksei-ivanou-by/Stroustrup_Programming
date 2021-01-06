#ifndef TASK_23_00_01_STDAFX_H
#include "Task_23_00_01_stdafx.h"
#endif

int main()
try
{
	Mail_file mfile{ "Task_23_00_01.txt" };

	std::multimap<std::string, const Message*> sender;

	for (const auto& m : mfile)
	{
		std::string s;
		if (find_from_addr(&m, s))
		{
			sender.insert(std::make_pair(s, &m));
		}
	}
	auto pp = sender.equal_range("John Doe <jdoe@machine.example>");
	for (auto p = pp.first; p != pp.second; ++p)
	{
		std::cout << find_subject(p->second) << '\n';
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