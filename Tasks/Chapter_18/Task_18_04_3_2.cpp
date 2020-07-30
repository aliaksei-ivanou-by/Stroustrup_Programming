#include <iostream>
#include "std_lib_facilities.h"

int my_strcmp(const char* s1, const char* s2, int s1_max = 128, int s2_max = 128)
{
	for (int i = 0; i < s1_max; ++i)
	{
		if (
			((*(s1 + i) == 0) || (i + 1 == s1_max)) 
			&& (*(s2 + i)) 
			&& ((s2_max > i + 1) || ((*(s1 + i)) < (*(s2 + i))))
			)
		{
			return -1;
		}
		if (
			((*(s2 + i) == 0) || (i + 1 == s2_max)) 
			&& (*(s1 + i)) 
			&& ((s1_max > i + 1) || ((*(s1 + i)) > (*(s2 + i))))
			)
		{
			return 1;
		}
	}
	return 0;
}

int main()
try
{
	// 1-1
	char s1_1_1[] = { 'a', 'b', 'c', 'd' };
	char s2_1_1[] = { 'z', 'y', 'x', 'w' };
	std::cout << my_strcmp(s1_1_1, s2_1_1, 4, 4) << '\n';

	// 2-2
	char s1_2_1[] = { 'z', 'y', 'x', 'w' };
	char s2_2_1[] = { 'a', 'b', 'c', 'd' };
	std::cout << my_strcmp(s1_2_1, s2_2_1, 4, 4) << '\n';

	// 3-1
	char s1_3_1[] = { 'a', 'b', 'c', 'd' };
	char s2_3_1[] = { 'a', 'b', 'c', 'd' };
	std::cout << my_strcmp(s1_3_1, s2_3_1, 4, 4) << '\n';

	// 1-2
	const char* s1_1_2 = "abcd";
	const char* s2_1_2 = "zyxw";
	std::cout << my_strcmp(s1_1_2, s2_1_2) << '\n';

	// 2-2
	const char* s1_2_2 = "zyxw";
	const char* s2_2_2 = "abcd";
	std::cout << my_strcmp(s1_2_2, s2_2_2) << '\n';

	// 3-2
	const char* s1_3_2 = "abcd";
	const char* s2_3_2 = "abcd";
	std::cout << my_strcmp(s1_3_2, s2_3_2) << '\n';
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