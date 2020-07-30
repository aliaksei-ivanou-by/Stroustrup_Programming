#include <iostream>
#include "std_lib_facilities.h"

int my_strcmp(const char* s1, const char* s2)
{
	while ((*s1) && (*s2))
	{
		if (*(s1) > * (s2))
		{
			return 1;
		}
		else
		{
			if (*(s1) < *(s2))
			{
				return -1;
			}
		}
		++s1;
		++s2;
	}
	if ((*(s1)) && !(*(s2)))
	{
		return 1;
	}
	if (!(*(s1)) && (*(s2)))
	{
		return -1;
	}
	if (s1 == s2)
	{
		return 0;
	}
}

int main()
try
{
	// 1
	char s1_1[] = { 'a', 'b', 'c', 'd' };
	char s2_1[] = { 'z', 'y', 'x', 'w' };
	std::cout << my_strcmp(s1_1, s2_1) << '\n';

	// 2
	char s1_2[] = { 'z', 'y', 'x', 'w' };
	char s2_2[] = { 'a', 'b', 'c', 'd' };
	std::cout << my_strcmp(s1_2, s2_2) << '\n';

	// 3
	char s1_3[] = { 'a', 'b', 'c', 'd' };
	char s2_3[] = { 'a', 'b', 'c', 'd' };
	std::cout << my_strcmp(s1_3, s2_3) << '\n';
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