#include <iostream>
#include "std_lib_facilities.h"

const char* my_findx(const char* s, const char* x, int s_max = 128, int x_max = 128)
{
	if (!*s)
	{
		return nullptr;
	}
	if (!*x)
	{
		return s;
	}
	for (int i = 0; *(s + i) && i < s_max; ++i)
	{
		if (*(s + i) == *x)
		{
			for (int j = 0; *(x + j) && j < x_max; ++j)
			{
				if (*(s + i + j) != *(x + j))
				{
					break;
				}
				if ((!*(x + j + 1)) || (j + 1 == x_max))
				{
					return (s + i);
				}
				if ((!*(s + i + j)) || (i + j == s_max))
				{
					return nullptr;
				}
			}
		}
	}
	return nullptr;
}

void print_char(const char* ch, int ch_max = 128)
{
	if (!*ch)
	{
		std::cout << "Null pointer\n";
		return;
	}
	int key = 0;
	while (*ch && key < ch_max)
	{
		std::cout << *ch++;
		key++;
	}
	std::cout << '\n';
	return;
}

int main()
try
{
	char ch1_1[] = { 'a', 'a', 'b', 'c' };
	char ch2_1[] = { 'b', 'c' };
	char ch3_1[] = { 'a', 'a', 'a' };

	const char* found_1 = my_findx(ch1_1, ch2_1, 4, 2);
	const char* not_found_1 = my_findx(ch1_1, ch3_1, 4, 3);

	if (found_1)
	{
		print_char(found_1, 2);
	}

	if (not_found_1)
	{
		print_char(not_found_1, 3);
	}

	std::cout << '\n';

	const char* ch1_2 = "aabc";
	const char* ch2_2 = "bc";
	const char* ch3_2 = "aaa";

	const char* found_2 = my_findx(ch1_2, ch2_2);
	const char* not_found_2 = my_findx(ch1_2, ch3_2);

	if (found_2)
	{
		print_char(found_2);
	}

	if (not_found_2)
	{
		print_char(not_found_2);
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