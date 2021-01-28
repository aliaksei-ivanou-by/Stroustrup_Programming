#ifndef TASK_27_00_02_STDAFX_HPP
#include "Task_27_00_02_stdafx.hpp"
#include "Task_27_00_02_my_strcpy.hpp"
#endif

char* my_strcpy(char* p, const char* q)
{
	char* temp = p;
	while (*p++ = *q++);
	return temp;
}