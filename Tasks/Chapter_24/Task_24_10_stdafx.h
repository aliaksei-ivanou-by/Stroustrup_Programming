#ifndef TASK_24_10_STDAFX_H
#define TASK_24_10_STDAFX_H

#include <iostream>
#include <random>

#endif

int randint(int max)
{
	static std::default_random_engine ran;
	int result = std::uniform_int_distribution<>{ 0, max }(ran);
	return result;
}
