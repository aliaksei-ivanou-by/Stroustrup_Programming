#include <iostream>

char* my_strdup(const char* ch)
{
	int l = 0;
	while (ch[l])
	{
		++l;
	}
	l++;
	char* s = new char[l + 1]{};
	for (int i = 0; i < l; ++i)
	{
		s[i] = ch[i];
	}
	s[l] = '\0';
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
	const char* ch1 = "A line in the memory";
	char* ch2 = my_strdup(ch1);
	print_char(ch2);

	char* ch_null = nullptr;
	print_char(ch_null);
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