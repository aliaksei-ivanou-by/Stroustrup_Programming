#include <iostream>

bool is_palindrom(const char* first, const char* last)
{
	while (first < last)
	{
		if (*first != *last)
		{
			return false;
		}
		++first;
		--last;
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
{
	const int max = 128;
	for (char s[max]; read_word(std::cin, s, max); )
	{
		std::cout << s << " is";
		if (!is_palindrom(&s[0], &s[strlen(s) - 1]))
		{
			std::cout << " not";
		}
		std::cout << " a palindrom\n";
	}
}