#ifndef TASK_25_07_STDAFX_H
#include "Task_25_07_stdafx.h"
#endif

int main()
try
{
	std::cout << "PART 1\n";
	for (int i = 0; i <= 400; ++i)
	{
		std::cout << std::dec << i << '\t' << std::hex << i << '\n';
	}
	std::cout << "\n\nPART 2\n";
	for (int i = -200; i <= 200; ++i)
	{
		std::cout << std::dec << i << '\t' << std::hex << i << '\n';
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