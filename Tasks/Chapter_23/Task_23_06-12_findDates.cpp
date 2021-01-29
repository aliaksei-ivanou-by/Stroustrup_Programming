#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <vector>
#include <sstream>
#include <iomanip>

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

int main()
try
{
	std::string fileName1 = "Task_23_06-12.txt";
	std::ifstream inputFileStream{ fileName1 };
	if (!inputFileStream)
	{
		throw std::runtime_error("Can't read file");
	}

	// find dates
	{
		int lineno = 0;
		std::string line;
		while (inputFileStream)
		{
			++lineno;
			std::getline(inputFileStream, line);
			if (findDates(line))
			{
				std::cout << lineno << ": " << line << '\n';
			}
		}
	}
	// dates to default
	{
		inputFileStream.clear();
		inputFileStream.seekg(0);
		std::string fileName2 = "Task_23_12_result.txt";
		std::ofstream outputFileStream{ fileName2 };
		for (std::string line; std::getline(inputFileStream, line); )
		{
			outputFileStream << dateToDefault(line) << '\n';
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