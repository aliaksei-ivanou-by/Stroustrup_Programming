#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <vector>

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

int main()
try
{
	std::string fileName = "Task_23_06.txt";
	std::ifstream inputFileStream{ fileName };
	if (!inputFileStream)
	{
		throw std::runtime_error("Can't read file");
	}

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
catch (const std::exception& e)
{
	std::cout << "Exception occured: " << e.what() << '\n';
	return 1;
}
catch (...)
{
	return 2;
}