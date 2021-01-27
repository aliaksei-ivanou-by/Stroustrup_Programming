#ifndef TASK_24_10_STDAFX
#include "Task_24_10_stdafx.h"
#include "Task_24_10_rand_int.h"
#endif

int rand_int(int max)
{
	static std::default_random_engine ran;
	int result = std::uniform_int_distribution<>{ 0, max }(ran);
	return result;
}
