#include <iostream>
#include <regex>
#include <string>
#include <fstream>
#include <sstream>

int main()
try
{
	std::regex pattern;

	std::string pat;
	std::cout << "Enter pattern: ";
	getline(std::cin, pat);
	try
	{
		pattern = pat;
		std::cout << "Pattern is: " << pat << '\n';
	}
	catch (std::regex_error)
	{
		std::cout << "Wrong pattern " << pat << '\n';
		exit(1);
	}

	std::cout << "Enter name of file:\n";
	std::string fileName;
	std::cin >> fileName;
	std::ifstream inputFileStream{ fileName };
	if (!inputFileStream)
	{
		throw ("Can't open file ", fileName);
	}

	int lineno = 0;
	for (std::string line; getline(inputFileStream, line); )
	{
		++lineno;
		std::smatch matches;
		if (std::regex_search(line, matches, pattern))
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