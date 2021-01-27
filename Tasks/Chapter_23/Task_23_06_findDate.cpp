#ifndef TASK_23_06_STDAFX
#include "Task_23_06_stdafx.h"
#include "Task_23_06_findDate.h"
#endif

bool findDates(const std::string& line)
{
	std::vector<std::regex> vec;

	// 01/01/2001
	vec.push_back(std::regex(R"(\d{1,2}/\d{1,2}/\d{4})"));

	// 01.01.2001
	vec.push_back(std::regex(R"(\d{1,2}[.]\d{1,2}[.]\d{4})"));

	// January 01, 2001
	vec.push_back(std::regex(R"((January|February|March|April|May|June|July|August|September|October|November|December)\s{1}\d{1,2}\,?\s{1}\d{4})"));

	for (const auto& i : vec)
	{
		if (std::regex_search(line, i))
		{
			return true;
		}
	}
	return false;
}