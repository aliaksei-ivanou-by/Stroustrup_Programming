#include <iostream>
#include <regex>

int main()
try
{
	std::string str = "\n";
	std::regex pat(".");
	if (std::regex_search(str, pat))
	{
		std::cout << "'.' matches '\\n' - YES";
	}
	else
	{
		std::cout << "'.' matches '\\n' - NO";
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