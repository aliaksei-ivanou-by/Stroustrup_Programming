#ifndef TASK_17_11_STDAFX
#include "Task_17_11_stdafx.h"
#include "Task_17_11_Link.h"
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
	if (this == nullptr)
	{
		return n;
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
	if (this == nullptr)
	{
		return n;
	}
	succ = n;
	n->prev = this;
	n->succ = nullptr;
	return this;
}

Link* Link::erase()
{
	if (this == nullptr)
	{
		return nullptr;
	}
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
	if (p == nullptr)
	{
		return nullptr;
	}
	if (n > 0)
	{
		while (n--)
		{
			if (p->succ == nullptr)
			{
				// std::cout << "Last element!\n";
				return p;
			}
			p = p->succ;
		}
	}
	if (n < 0)
	{
		while (n++)
		{
			if (p->prev == nullptr)
			{
				// std::cout << "First element!\n";
				return p;
			}
			p = p->prev;
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