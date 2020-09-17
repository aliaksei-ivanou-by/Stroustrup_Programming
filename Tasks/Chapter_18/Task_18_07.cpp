#include <iostream>
#include "std_lib_facilities.h"

size_t my_strlen(const char* ch)
{
	if (!ch)
	{
		return 0;
	}
	size_t l = 0;
	while (*ch++)
	{
		++l;
	}
	return l;
}

char* cat_dot(const char* s1, const char* s2, const char* delimeter = ".")
{
	if (!s1 || !s2 || !delimeter)
	{
		return nullptr;
	}
	size_t s1_sz = my_strlen(s1);
	size_t s2_sz = my_strlen(s2);
	size_t delimeter_sz = my_strlen(delimeter);
	size_t result_sz = s1_sz + delimeter_sz + s1_sz + 1;
	char* result = new char[result_sz];
	for (size_t i = 0; i < s1_sz; ++i)
	{
		result[i] = *(s1++);
	}
	for (size_t i = s1_sz; i < s1_sz + delimeter_sz; ++i)
	{
		result[i] = *(delimeter++);
	}
	for (size_t i = s1_sz + delimeter_sz; i < result_sz - 1; ++i)
	{
		result[i] = *(s2++);
	}
	result[result_sz] = '\0';
	return result;
}

int main()
try
{
	char s1[] = "Niels";
	char s2[] = "Bohr";

	char* result = cat_dot(s1, s2, " ... ");

	if (result)
	{
		std::cout << result << '\n';
	}

	delete result;
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