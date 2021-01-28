#ifndef TASK_27_01_STDAFX_HPP
#include "Task_27_01_stdafx.hpp"
#include "Task_27_01_func.hpp"
#endif

size_t my_strlen(const char* ch)
{
	size_t size = 0;
	while (*ch++)
	{
		++size;
	}
	return size;
}

int my_strcmp(const char* leftCh, const char* rightCh)
{
	const char* leftChar = leftCh;
	const char* rightChar = rightCh;
	while (*leftChar && *rightChar && *leftChar == *rightChar)
	{
		++leftChar;
		++rightChar;
	}
	if (*leftChar > *rightChar)
	{
		return 1;
	}
	else
	{
		if (*leftChar < *rightChar)
		{
			return -1;
		}
		else
		{
			return 0;
		}
	}
}

char* my_strcpy(char* outCh, const char* inCh)
{
	char* result = outCh;
	while (*outCh++ = *inCh++);
	return result;
}