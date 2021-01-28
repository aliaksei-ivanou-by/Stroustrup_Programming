#ifndef TASK_25_00_04_STDAFX_H
#include "Task_25_00_04_stdafx.h"
#include "Task_25_00_04_infinite.h"
#endif

void infinite()
{
	unsigned char max = 160;
	for (signed char i = 0; i < max; ++i) // ranges of 'i' - [-128, 127]
	{
		std::cout << int(i) << '\n';
	}
}