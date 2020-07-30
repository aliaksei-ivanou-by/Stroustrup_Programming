#include <iostream>
#include "std_lib_facilities.h"

bool is_palindrome(const std::string& s)
{
	int first = 0;
	int last = s.length() - 1;
	while (first < last)
	{
		if (s[first] != s[last])
		{
			return false;
		}
		++first;
		--last;
	}
	return true;
}

int main()
try
{
	for (std::string s; std::cin >> s; )
	{
		std::cout << "String '" << s << "' is";
		if (!is_palindrome(s))
		{
			std::cout << " not";
		}
		std::cout << " a palindrom\n";

		std::string s_rev = s;
		std::reverse(s_rev.begin(), s_rev.end());
		std::cout << "Reverse string is '";
		std::cout << s_rev << "'\n";
		std::cout << "String and reverse string are";
		if ( s == s_rev)
		{
			std::cout << " equal\n\n";
		}
		else
		{
			std::cout << " not equal\n\n";
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