#include <iostream>
#include <climits>

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

std::istream& read_word(std::istream& is, char*& buffer)
{
	int max = 0;
	char* t = new char();
	*t = 0;
	char ch;
	while (is.get(ch))
	{
		if (ch == '\n')
		{
			break;
		}
		t[strlen(t) + 1] = 0;
		t[strlen(t)] = ch;
	}
	buffer = t;
	return is;
}

int main()
try
{
	char* s = 0;
	while (read_word(std::cin, s))
	{
		std::cout << s << " is";
		if (!is_palindrome(s, strlen(s)))
		{
			std::cout << " not";
		}
		std::cout << " a palindrome\n";
		delete s;
	}
	delete s;
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