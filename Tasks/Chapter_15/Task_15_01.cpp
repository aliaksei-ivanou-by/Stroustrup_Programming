#ifndef TASK_15_01_STDAFX_H
#include "Task_15_01_stdafx.h"
#endif

int main(int argc, char** argv)
try
{
	for (int i = 0; i <= 20; ++i)
	{
		std::cout << "Step " << i << "\t" << fac(i) << '\n';
	}
	return 0;
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