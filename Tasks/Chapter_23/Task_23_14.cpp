#include <iostream>
#include <fstream>
#include <sstream>
#include <regex>

int main()
try
{
	std::string fileName{ "Task_23_14.txt" };
	std::ifstream inputFileStream(fileName);
	if (!inputFileStream)
	{
		throw std::runtime_error("Can't open file");
	}

	std::string line;
	std::string lines;
	while (getline(inputFileStream, line))
	{
		lines += line + "\n";
	}

	std::string pat;
	std::regex pattern;
	std::string exit = "exit";
	std::string invitation = "Enter pattern ('" + exit + "' to exit) : ";
	std::cout << invitation << '\n';
	while (getline(std::cin, pat))
	{
		if (pat == exit)
		{
			break;
		}
		try
		{
			pattern = pat;
		}
		catch (std::regex_error)
		{
			std::cout << pat << " is wrong regular expression\n";
			std::exit(1);
		}

		std::smatch matches;
		if (std::regex_search(lines, matches, pattern))
		{
			std::cout << "Match found:\n" << matches[0] << '\n';
		}
		else
		{
			std::cout << "No match found\n";
		}
		std::cout << invitation;
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