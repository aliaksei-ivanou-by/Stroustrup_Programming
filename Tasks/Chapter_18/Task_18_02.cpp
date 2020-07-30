#include <iostream>
#include "std_lib_facilities.h"

const char* my_findx(const char* s, const char* x)
{
	if (x == nullptr)
	{
		return s;
	}
	for (int i = 0; *(s + i); ++i)
	{
		if (*(s + i) == *x)
		{
			for (int j = 1; *(x + j); ++j)
			{
				if (*(s + i + j) != *(x + j))
				{
					break;
				}
				if (*(x + j + 1) == 0)
				{
					return &(*(s + i));
				}
				if (*(s + i + j + 1) == 0)
				{
					return nullptr;
				}
			}
		}
	}
	return nullptr;
}

void print_char(const char* ch)
{
	if (!*ch)
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
	const char* ch1 = "aabc";
	const char* ch2 = "bc";
	const char* ch3 = "aaa";

	const char* found = my_findx(ch1, ch2);
	const char* not_found = my_findx(ch1, ch3);

	if (found)
	{
		print_char(found);
	}

	if (not_found)
	{
		print_char(not_found);
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