#ifndef TASK_25_00_03_STDAFX_H
#include "Task_25_00_03_stdafx.h"
#endif

int main()
try
{
	for (int i; std::cin >> i; )
	{
		std::cout << std::dec << i << " = " <<
			std::hex << std::showbase << i << " = " <<
			std::bitset<8 * sizeof(int)>(i) << '\n';
	}
}
catch (const std::exception& e)
{
	std::cout << "Exception occured: " << e.what() << '\n';
	return 1;
}
catch (...)
{
	return 2;
}