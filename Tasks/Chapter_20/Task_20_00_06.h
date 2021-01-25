#ifndef TASK_20_00_06_H
#define TASK_20_00_06_H

#include <list>

class Line;

struct Document
{
	std::list<Line> line;
	void erase_line(int n);
};

template<typename Iter>
void advance(Iter& p, int n)
{
	while (n > 0)
	{
		++p;
		--n;
	}
	if (n < 0)
	{
		--p;
		++n;
	}
}

#endif