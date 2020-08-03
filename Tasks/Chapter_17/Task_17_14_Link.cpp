#ifndef TASK_17_14_STDAFX
#include "Task_17_14_stdafx.h"
#include "Task_17_14_Link.h"
#endif

God::God(const std::string& n, const std::string& m, const std::string& v, const std::string& w)
	: name{ n },
	mythology{ m },
	vehicle{ v },
	weapon{ w }
{
}

std::ostream& operator<<(std::ostream& os, const God& g)
{
	return os << "{ " <<
		g.name << ", " <<
		g.mythology << ", " <<
		g.vehicle << ", " <<
		g.weapon << " }\n";
}

Link::Link(God g, Link* s)
	: god{ g },
	succ{ s }
{
}

Link* Link::insert(Link* n)
{
	if (n == nullptr)
	{
		return this;
	}
	n->succ = this;
	return n;
}

Link* Link::erase()
{
	if (succ == nullptr)
	{
		return this;
	}
	if (succ->succ)
	{
		succ = succ->succ;
		succ->succ = nullptr;
	}
	else
	{
		succ = nullptr;
	}
	return this;
}

Link* Link::find(const std::string& s)
{
	Link* p = this;
	while (p)
	{
		if (p->god.name == s)
		{
			return p;
		}
		p = p->succ;
	}
	return nullptr;
}

const Link* Link::find(const std::string& s) const
{
	const Link* p = this;
	while (p)
	{
		if (p->god.name == s)
		{
			return p;
		}
		p = p->succ;
	}
	return nullptr;
}

Link* Link::advance(int n) const
{
	Link* p = const_cast<Link*>(this);
	if (n > 0)
	{
		while (n--)
		{
			if (succ == nullptr)
			{
				return nullptr;
			}
			p = succ;
		}
	}
	return p;
}

Link* Link::next() const
{
	return succ;
}

void print_all(Link* n)
{
	if (n == nullptr)
	{
		return;
	}
	Link* p = n;
	while (p)
	{
		std::cout << p->god;
		p = p->next();
	}
}
