#ifndef TASK_24_00_02_STDAFX_H
#include "Task_24_00_02_stdafx.h"
#include "Task_24_00_02_func.h"
#endif

void f(int i, double fpd)
{
	std::cout << "i = " << i << '\t';
	char c = i;
	std::cout << "c = " << c << '\n';

	std::cout << "i = " << i << '\t';
	short s = i;
	std::cout << "s = " << s << '\n';

	std::cout << "i + i = " << i + i << '\t';
	i = i + i;
	std::cout << "i = i + i = " << i << '\n';

	std::cout << "i * i = " << i * i << '\t';
	long lg = i * i;
	std::cout << "lg = i * i = " << lg << '\n';

	std::cout << "fpd = " << fpd << '\t';
	float fps = fpd;
	std::cout << "fps = " << fps << '\n';

	std::cout << "fpd = " << fpd << '\t';
	i = fpd;
	std::cout << "i = " << i << '\n';

	std::cout << "i = " << i << '\t';
	fps = i;
	std::cout << "fps = " << fps << '\n';
}

void g()
{
	char ch = 0;
	for (int i = 0; i < 500; ++i)
	{
		std::cout << int(ch++) << '\t';
	}
}