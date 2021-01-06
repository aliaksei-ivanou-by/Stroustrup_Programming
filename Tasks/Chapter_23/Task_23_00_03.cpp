#include <regex>
#include <iostream>
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
		std::cout << "Pattern: " << pat << '\n';
	}
	catch (std::regex_error)
	{
		std::cout << "Wrong pattern\n";
		exit(1);
	}
	std::cout << "Enter lines:\n";
	int lineno = 0;
	for (std::string line; getline(std::cin, line); )
	{
		++lineno;
		std::smatch matches;
		if (std::regex_search(line, matches, pattern))
		{
			std::cout << "Line " << lineno << ": " << line << '\n';
			for (int i = 0; i < matches.size(); ++i)
			{
				std::cout << "\tmatches[" << i << "]: " << matches[i] << '\n';
			}
		}
		else
		{
			std::cout << "No match\n";
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