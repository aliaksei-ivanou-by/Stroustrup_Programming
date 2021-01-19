#ifndef TASK_27_00_02_STDAFX_HPP
#include "Task_27_00_02_stdafx.hpp"
#endif

int main()
{
	char* ch1 = "abcdef";
	char* ch2 = 0;
	ch2 = (char*)malloc(sizeof(char) * (strlen(ch1) + 1));
	if (!ch2)
	{
		perror("Can't allocate memory");
	}
	ch2 = my_strcpy(ch2, ch1);
	printf("ch1: %s, ch2: %s", ch1, ch2);
}