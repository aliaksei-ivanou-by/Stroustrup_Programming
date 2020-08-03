#ifndef TASK_17_12_STDAFX
#include "Task_17_12_stdafx.h"
#include "Task_17_12_Link.h"
#endif

Link::Link(const std::string& v, Link* p, Link* s)
	: value{ v },
	prev{ p },
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
	if (prev)
	{
		prev->succ = n;
	}
	n->prev = prev;
	prev = n;
	return n;
}

Link* Link::add(Link* n)
{
	if (n == nullptr)
	{
		return this;
	}
	succ = n;
	n->prev = this;
	n->succ = nullptr;
	return this;
}

Link* Link::erase()
{
	if (prev)
	{
		prev->succ = succ;
	}
	if (succ)
	{
		succ->prev = prev;
	}
	return succ;
}

Link* Link::find(const std::string& s)
{
	Link* p = this;
	while (p)
	{
		if (p->value == s)
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
		if (p->value == s)
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
	if (n < 0)
	{
		while (n++)
		{
			if (prev == nullptr)
			{
				return nullptr;
			}
			p = prev;
		}
	}
	return p;
}

Link* Link::next() const
{
	return succ;
}

Link* Link::previous() const
{
	return prev;
}

void print_all(Link* p)
{
	std::cout << "{ ";
	while (p)
	{
		std::cout << p->value;
		if (p = p->next())
		{
			std::cout << ", ";
		}
	}
	std::cout << " }";
}