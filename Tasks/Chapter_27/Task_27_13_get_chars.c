#ifndef TASK_27_13_STDAFX_HPP
#include "Task_27_13_stdafx.hpp"
#include "Task_27_13_get_chars.hpp"
#endif

char* get_chars()
{
	int size = 0;
	int i = 0;
	int letter = 0;
	char* ch = (char*)malloc(sizeof(char) * size);
	while ((letter = getchar()) != EOF && letter != '\n')
	{
		if (i >= size)
		{
			++size;
			char* temp = (char*)realloc(ch, sizeof(char) * size);
			ch = temp;
		}
		ch[i] = letter;
		++i;
	}
	ch[i] = 0;
	return ch;
}