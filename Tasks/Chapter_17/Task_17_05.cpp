#include <iostream>
#include "std_lib_facilities.h"

const char* my_findx(const char* s, const char* x)
{
	if (x == nullptr)
	{
		return s;
	}
	for (int i = 0; s[i]; ++i)
	{
		if (s[i] == x[0])
		{
			for (int j = 1; x[j]; ++j)
			{
				if (s[i + j] != x[j])
				{
					break;
				}
				if (x[j + 1] == 0)
				{
					return &s[i];
				}
				if (s[i + j + 1] == 0)
				{
					return nullptr;
				}
			}
		}
	}
	return nullptr;
}

int main()
try
{
	char ch1[] = "aabc";
	char ch2[] = "bc";
	char ch3[] = "aaa";

	const char* found = my_findx(ch1, ch2);
	const char* not_found = my_findx(ch1, ch3);

	if (found)
	{
		std::cout << found << '\n';
	}

	if (not_found)
	{
		std::cout << not_found << '\n';
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