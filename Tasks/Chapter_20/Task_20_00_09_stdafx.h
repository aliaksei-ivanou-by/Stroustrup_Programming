#ifndef TASK_20_00_09_STDAFX_H
#define TASK_20_00_09_STDAFX_H

#include <iostream>
#include <array>
#include <vector>
#include <list>

#endif

template<typename T>
void print(const T& myClass, const std::string& message)
{
	std::cout << message << " : \t";
	for (auto& i : myClass)
	{
		std::cout << i << ' ';
	}
	std::cout << '\n';
}

// 6
template<typename Iter1, typename Iter2>
Iter2 myCopy(Iter1 f1, Iter1 e1, Iter2 f2)
{
	for (Iter1 p = f1; p != e1; ++p)
	{
		*f2++ = *p;
	}
	return f2;
}
