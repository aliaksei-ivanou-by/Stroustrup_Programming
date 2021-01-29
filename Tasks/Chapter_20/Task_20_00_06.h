#include <list>

class Line;

struct Document
{
	std::list<Line> line;
	void erase_line(int n)
	{
		if (n < 0 || (*this).line.size() - 1 <= n)
		{
			return;
		}
		auto p = (*this).line.begin();
		advance(p, n);
		(*this).line.erase(p);
	}
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