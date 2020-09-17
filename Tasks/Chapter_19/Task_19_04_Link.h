#ifndef TASK_19_04_LINK_H
#define TASK_19_04_LINK_H

#ifndef TASK_19_04_STDAFX_H
#include "Task_19_04_stdafx.h"
#endif

template<typename T>
class Link
{
public:
	T value;
	Link<T>(T v, Link<T>* p = nullptr, Link<T>* s = nullptr):
		value{ v },
		prev{ p },
		succ{ s }
	{}
	Link<T>* insert(Link<T>* n)
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
	Link<T>* add(Link<T>* n)
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
	Link<T>* erase()
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
	Link<T>* find(const std::string& s)
	{
		Link<T>* p = this;
		while (p)
		{
			if (p->value.name == s)
			{
				return p;
			}
			p = p->succ;
		}
		return nullptr;
	}
	const Link<T>* find(const std::string& s) const
	{
		const Link<T>* p = this;
		while (p)
		{
			if (p->value.name == s)
			{
				return p;
			}
			p = p->succ;
		}
		return nullptr;
	}
	Link<T>* add_ordered(Link<T>* n)
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
			Link<T>* p = this;
			if (!(p->value < n->value))
			{
				p->add(n);
				return n;
			}
			while (!(n->value < p->value))
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
	Link<T>* advance(int n) const
	{
		Link<T>* p = const_cast<Link<T>*>(this);
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
	Link<T>* next() const
	{
		return succ;
	}
	Link<T>* previous() const
	{
		return prev;
	}
	Link<T>* update()
	{
		Link<T>* p = this;
		this->erase();
		p->succ = nullptr;
		p->prev = nullptr;
		return p;
	}
	friend void print_all(Link<T>* n)
	{
		if (n == nullptr)
		{
			return;
		}
		Link<T>* p = n;
		while (p->next())
		{
			p = p->next();
		}
		while (p)
		{
			std::cout << p->value;
			p = p->previous();
		}
	}
private:
	Link<T>* prev;
	Link<T>* succ;
};

#endif