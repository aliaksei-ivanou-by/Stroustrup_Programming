#ifndef TASK_24_00_02_STDAFX_H
#include "Task_24_00_02_stdafx.h"
#endif

int main()
try
{
	std::cout << "g()\n";
	g();

	std::cout << "f() max\n";
	int i = std::numeric_limits<int>::max();
	double d = std::numeric_limits<double>::max();
	f(i, d);

	std::cout << "f() min\n";
	i = std::numeric_limits<int>::min();
	d = std::numeric_limits<double>::min();
	f(i, d);
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