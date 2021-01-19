#ifndef TASK_25_03_STDAFX_H
#define TASK_25_03_STDAFX_H

#include <iostream>
#include <bitset>
#include <iomanip>

#endif

template<class T>
void print(T value)
{
	std::cout << std::setw(20) << value << '\t' << std::bitset<32>(value) << '\n';
}
