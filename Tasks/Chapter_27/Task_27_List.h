#pragma once
#include <iostream>

class Link
{
public:
	Link* prev;
	Link* next;
	Link():
		prev{ nullptr },
		next{ nullptr }
	{}
	virtual void print(std::ostream& os) const
	{};
};

struct Link* advance(struct Link* p, int n)
{
	if (!p)
	{
		return nullptr;
	}
	Link* curr = p;
	if (n == 0)
	{
		return p;
	}
	else
	{
		if (n > 0)
		{
			while (n--)
			{
				curr = curr->next;
			}
		}
		else
		{
			while (n++)
			{
				curr = curr->prev;
			}
		}
	}
	return curr;
}

class Name : public Link
{
private:
	std::string name;
public:
	Name() :
		Link(),
		name{}
	{}
	Name(std::string name) :
		Link(),
		name{ name }
	{}
	std::string get_name() const
	{
		return name;
	}
	virtual void print(std::ostream& os) const
	{
		os << name;
	};
};

std::ostream& operator<<(std::ostream& os, const Link& l)
{
	l.print(os);
	return os;
}

class List
{
private:
	Link* first;
	Link* last;
public:
	List():
		first{ nullptr },
		last{ nullptr }
	{}
	~List()
	{
		Link* curr = first;
		while (curr)
		{
			Link* temp = curr->next;
			delete (curr);
			curr = temp;
		}
	}
	Link* begin() const
	{
		return first;
	}
	Link* end() const
	{
		return last;
	}
	void push_back(Link* p)
	{
		Link* last = this->last;
		if (last)
		{
			last->next = p;
			p->prev = last;
		}
		else
		{
			this->first = p;
			p->prev = 0;
		}
		this->last = p;
		p->next = 0;
	}
	void push_front(Link* p)
	{
		Link* curr = first;
		if (curr)
		{
			curr->prev = p;
			p->next = curr;
		}
		else
		{
			last = p;
			p->next = nullptr;
		}
		first = p;
		p->prev = nullptr;
	}
	void insert(Link* p, Link* q)
	{
		q->next = p;
		if (p == first)
		{
			q->prev = 0;
			first = q;
		}
		else if (p == last)
		{
			if (p->prev)
			{
				q->prev = p->prev;
				p->prev->next = q;
			}
			else
			{
				q->next = 0;
			}
		}
		else
		{
			q->prev = p->prev;
			p->prev->next = q;
		}
		p->prev = q;
	}
	Link* erase(Link* p)
	{
		if (p == 0)
		{
			return nullptr;
		}
		if (p == first)
		{
			if (p->next)
			{
				first = p->next;
				p->next->prev = nullptr;
				return p->next;
			}
			else
			{
				first = nullptr;
				last = nullptr;
				return nullptr;
			}
		}
		else
		{
			if (p == last)
			{
				if (p->prev)
				{
					last = p->prev;
					p->prev->next = 0;
				}
				else
				{
					first = nullptr;
					last = nullptr;
					return nullptr;
				}
			}
			else
			{
				p->next->prev = p->prev;
				p->prev->next = p->next;
				return p->next;
			}
		}
	}
	void print()
	{
		Link* i = begin();
		while (i)
		{
			std::cout << *i << '\n';
			i = i->next;
		}
	}
};