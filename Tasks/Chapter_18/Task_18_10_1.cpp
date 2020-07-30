#include <iostream>

bool is_palindrome(const char s[], int n)
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
	if (strlen(buffer) == (max - 1))
	{
		std::cout << "String cut off after " << max - 1 << " chars\n";
		char ch;
		while (is.get(ch))
		{
			if (ch == '\n')
			{
				break;
			}
		}
	}
	return is;
}

int main()
try
{
	constexpr int max = 10;
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
catch (const std::exception& e)
{
	std::cout << "Exception occured: " << e.what() << '\n';
	return 1;
}
catch (...)
{
	return 2;
}