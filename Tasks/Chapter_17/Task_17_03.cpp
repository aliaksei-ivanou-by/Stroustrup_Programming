#include <iostream>

void to_lower(char* s)
{
	do
	{
		if (*s >= 'A' && *s <= 'Z')
		{
			*s += 'a' - 'A';
		}
	} while (*s++ && *s != '0');
}

int main()
try
{
	char ch_temp[] = "HELLO, WORLD!";
	char* ch = ch_temp;
	std::cout << ch << '\n';
	to_lower(ch);
	std::cout << ch << '\n';
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