#ifndef TASK_27_13_STDAFX_HPP
#define TASK_27_13_STDAFX_HPP

#include <stdlib.h>
#include <stdio.h>

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