#include <iostream>

char* my_strdup(const char* ch)
{
	int l = 0;
	while (ch[l])
	{
		++l;
	}
	l++;
	char* s = new char[l];
	for (int i = 0; i < l; ++i)
	{
		s[i] = ch[i];
	}
	return s;
}

int main()
try
{
	char ch1[] = "A line in the memory";
	char* ch2 = my_strdup(ch1);
	for (int i = 0; ch2[i]; ++i)
	{
		std::cout << ch2[i];
	}
	std::cout << '\n';
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