#include <iostream>
#include <string>
#include "std_lib_facilities.h"

int main()
try
{
	std::string str;
	char c;
	constexpr char exit = '!';

	while (true)
	{
		std::cin >> c;
		if (c == exit)
		{
			break;
		}
		str.push_back(c);
	}
	std::cout << str << '\n';
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