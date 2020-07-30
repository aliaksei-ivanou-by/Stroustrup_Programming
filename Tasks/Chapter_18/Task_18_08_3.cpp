#include <iostream>
#include "std_lib_facilities.h"

bool is_palindrome(const char* first, const char* last)
{
	while (first < last)
	{
		if (*first != *last)
		{
			return false;
		}
		return is_palindrom(first + 1, last - 1);
	}
	return true;
}

std::istream& read_word(std::istream& is, char* buffer, int max)
{
	is.width(max);
	is >> buffer;
	return is;
}

int main()
try
{
	const int max = 128;
	for (char s[max]; read_word(std::cin, s, max); )
	{
		std::cout << "String '" << s << "' is";
		if (!is_palindrome(&s[0], &s[strlen(s) - 1]))
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