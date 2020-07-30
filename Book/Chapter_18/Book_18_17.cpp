#include <iostream>

bool is_palindrom(const char s[], int n)
{
	int first = 0;
	int last = n - 1;
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

std::istream& read_word(std::istream& is, char* buffer, int max)
{
	is.width(max);
	is >> buffer;
	return is;
}

int main()
{
	constexpr int max = 128;
	for (char s[max]; read_word(std::cin, s, max); )
	{
		std::cout << s << " is";
		if (!is_palindrom(s, strlen(s)))
		{
			std::cout << " not";
		}
		std::cout << " a palindrom\n";
	}
}