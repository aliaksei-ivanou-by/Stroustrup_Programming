#include <regex>
#include <iostream>
#include <string>
#include <fstream>

int main()
try
{
	std::ifstream inputFileStream{ "Task_23_00_04.txt" };
	if (!inputFileStream)
	{
		std::cerr << "No file\n";
		throw std::runtime_error("No file");
	}
	std::regex pattern(R"(\w{2}\s*\d{5}(-\d{4})?)");

	int lineno = 0;
	for (std::string line; getline(inputFileStream, line); )
	{
		++lineno;
		std::smatch matches;
		std::cout << lineno << " : ";
		if (std::regex_search(line, matches, pattern))
		{
			std::cout << matches[0] << '\n';
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