#ifndef TASK_23_12_STDAFX_H
#define TASK_23_12_STDAFX_H

#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <vector>

#endif

bool findDates(const std::string& line)
{
	std::vector<std::regex> vec;

	// 01/01/2001
	vec.push_back(std::regex(R"((\d{1,2})/(\d{1,2})/(\d{4}))"));

	// 01.01.2001
	vec.push_back(std::regex(R"(\d{1,2}[.]\d{1,2}[.]\d{4})"));

	// January 01, 2001
	vec.push_back(std::regex(R"([A-Za-z]+\s{1}\d{1,2}\,?\s{1}\d{4})"));

	for (const auto& i : vec)
	{
		if (std::regex_search(line, i))
		{
			return true;
		}
	}
	return false;
}

std::string dateToDefault(std::string line)
{
	std::vector<std::regex> vec;

	// 01/01/2001
	vec.push_back(std::regex(R"((\d{1,2})(/)(\d{1,2})(/)(\d{4}))"));
	// 01.01.2001
	vec.push_back(std::regex(R"((\d{1,2})([.])(\d{1,2})([.])(\d{4}))"));
	// 01 01 2001
	vec.push_back(std::regex(R"((\d{1,2})([ ])(\d{1,2})([ ])(\d{4}))"));
	// January 01, 2001
	vec.push_back(std::regex(R"(([A-Za-z]+)(\,?\s{0,}?)(\d{1,2})(\,?\s{0,})(\d{4}))"));

	for (const auto& i : vec)
	{
		if (std::regex_search(line, i))
		{
			return std::regex_replace(line, i, "$5-$1-$3");
		}
	}
	return "";
}