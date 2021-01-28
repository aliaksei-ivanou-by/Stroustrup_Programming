#ifndef TASK_20_00_06_STDAFX_H
#include "Task_20_00_06.h"
#endif

void Document::erase_line(int n)
{
	if (n < 0 || (*this).line.size() - 1 <= n)
	{
		return;
	}
	auto p = (*this).line.begin();
	advance(p, n);
	(*this).line.erase(p);
}
