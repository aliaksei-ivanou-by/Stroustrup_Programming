#include <iostream>

bool is_palindrom(const std::string& s)
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
{
	for (std::string s; std::cin >>s; )
	{
		std::cout << s << " is ";
		if (!is_palindrom(s))
		{
			std::cout << " not";
		}
		std::cout << " a palindrom\n";
	}
}