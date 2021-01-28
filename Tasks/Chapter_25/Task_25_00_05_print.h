#ifndef TASK_25_00_05_PRINT_H
#define TASK_25_00_05_PRINT_H

#ifndef TASK_25_00_05_STDAFX_H
#include "Task_25_00_05_stdafx.h"
#endif

template<typename T>
void print(T value)
{
	std::cout << static_cast<int>(value) << '\t';
}

#endif