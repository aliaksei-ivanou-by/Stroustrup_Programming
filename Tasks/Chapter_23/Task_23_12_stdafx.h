#ifndef TASK_23_12_STDAFX_H
#define TASK_23_12_STDAFX_H

#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <vector>
#include <sstream>
#include <iomanip>

#endif

std::string findMonth(const std::string& line)
{
	std::string month;
	std::vector<std::string> monthes{ 
		"January", "February", "March", "April", "May", "June",
		"July", "August", "September", "October", "November", "December" 
	};
	for (size_t i = 0; i < monthes.size(); ++i)
	{
		std::string find = monthes[i];
		if (line.find(find) != std::string::npos)
		{
			std::ostringstream outputStringStream;
			outputStringStream << std::setfill('0') << std::setw(2) << i + 1;
			return outputStringStream.str();
		}
	}
}

std::string dateToDefault(const std::string& line)
{
	std::vector<std::regex> vec;

	// 01/01/2001
	vec.push_back(std::regex(R"((\d{1,2})(/)(\d{1,2})(/)(\d{4}))"));
	// 01.01.2001
	vec.push_back(std::regex(R"((\d{1,2})([.])(\d{1,2})([.])(\d{4}))"));
	// 01 01 2001
	vec.push_back(std::regex(R"((\d{1,2})([ ])(\d{1,2})([ ])(\d{4}))"));
	// January 01, 2001
	std::regex date(R"((January|February|March|April|May|June|July|August|September|October|November|December)(\,?\s{0,}?)(\d{1,2})(\,?\s{0,})(\d{4}))");

	for (const auto& i : vec)
	{
		if (std::regex_search(line, i))
		{
			return std::regex_replace(line, i, "$5-$1-$3");
		}
	}
	if (std::regex_search(line, date))
	{
		std::string dateToRegex = "$5-" + findMonth(line) + "-$3";
		return std::regex_replace(line, date, dateToRegex);
	}
	return "";
}