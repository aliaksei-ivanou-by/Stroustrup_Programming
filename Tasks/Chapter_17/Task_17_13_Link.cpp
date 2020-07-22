#ifndef TASK_17_13_STDAFX
#include "Task_17_13_stdafx.h"
#include "Task_17_13_Link.h"
#endif

God::God(const std::string& n, const std::string& m, const std::string& v, const std::string& w)
	: name{ n },
	mythology{ m },
	vehicle{ v },
	weapon{ w }
{
}

bool operator<(const God& g1, const God& g2)
{
	return g1.name < g2.name;
}

std::ostream& operator<<(std::ostream& os, const God& g)
{
	return os << "{ " <<
		g.name << ", " <<
		g.mythology << ", " <<
		g.vehicle << ", " <<
		g.weapon << " }\n";
}

Link::Link(God g, Link* p, Link* s)
	: god{ g },
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

Link* Link::add_ordered(Link* n)
{
	if (n == nullptr)
	{
		return this;
	}
	if (this == nullptr)
	{
		n->succ = nullptr;
		n->prev = nullptr;
		return n;
	}
	else
	{
		Link* p = this;
		if (!(p->god < n->god))
		{
			p->add(n);
			return n;
		}
		while (!(n->god < p->god))
		{
			if (!(p->previous()))
			{
				p->insert(n);
				return this;
			}
			p = p->previous();
		}
		p->add(n);
	}
	return this;
}

Link* Link::update()
{
	if (this == nullptr)
	{
		return nullptr;
	}
	Link* p = this;
	this->erase();
	p->succ = nullptr;
	p->prev = nullptr;
	return p;
}

void print_all(Link* n)
{
	if (n == nullptr)
	{
		return;
	}
	Link* p = n;
	while (p->next())
	{
		p = p->next();
	}
	while (p)
	{
		std::cout << p->god;
		p = p->previous();
	}
}
