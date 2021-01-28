#ifndef TASK_25_00_05_STDAFX_H
#include "Task_25_00_05_stdafx.h"
#endif

int main()
try
{
	int si = 257;
	char c = si;
	unsigned char uc = si;
	signed char sc = si;
	print(si);
	print(c);
	print(uc);
	print(sc);
	std::cout << '\n';

	si = 129;
	c = si;
	uc = si;
	sc = si;
	print(si);
	print(c);
	print(uc);
	print(sc);
	std::cout << '\n';

	si = 128;
	c = si;
	uc = si;
	sc = si;
	print(si);
	print(c);
	print(uc);
	print(sc);
	std::cout << '\n';
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