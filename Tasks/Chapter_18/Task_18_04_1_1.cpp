#include <iostream>

char* my_strdup(const char* ch)
{
	int l = 0;
	while (*(ch + l))
	{
		++l;
	}
	l++;
	char* s = new char[l];
	for (int i = 0; i < l; ++i)
	{
		*(s + i) = *(ch + i);
	}
	return s;
}

void print_char(const char* ch)
{
	if (!ch)
	{
		std::cout << "Null pointer\n";
		return;
	}
	while (*ch)
	{
		std::cout << *ch++;
	}
	std::cout << '\n';
	return;
}

int main()
try
{
	char ch1[] = { 'A', ' ', 'l', 'i', 'n', 'e', ' ', 'i', 'n', ' ', 't', 'h', 'e', ' ', 'm', 'e', 'm', 'o', 'r', 'y' };
	char* ch2 = my_strdup(ch1);
	print_char(ch2);
	delete[] ch2;
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