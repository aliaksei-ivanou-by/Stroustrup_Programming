#ifndef TASK_25_03_PRINT_H
#define TASK_25_03_PRINT_H

#ifndef TASK_25_03_STDAFX_H
#include "Task_25_03_stdafx.h"
#endif

template<class T>
void print(T value)
{
	std::cout << std::setw(20) << value << '\t' << std::bitset<32>(value) << '\n';
}


#endif