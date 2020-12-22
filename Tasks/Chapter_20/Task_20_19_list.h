#ifndef TASK_20_19_LIST_H
#define TASK_20_19_LIST_H

#ifndef TASK_20_19_STDAFX_H
#include "Task_20_19_stdafx.h"
#endif

template<class Elem>
class Link
{
public:
	Link(const Elem& v = Elem(), Link* p = nullptr, Link* s = nullptr) :
		prev{ p },
		succ{ s },
		val{ v }
	{}
	Link* prev;
	Link* succ;
	Elem val;
};

template<class Elem>
class list
{
private:
	int sz;
	Link<Elem>* first;
	Link<Elem>* last;
public:
	list() :
		first{ std::make_unique<Link<Elem>>().release() },
		last{ first }
	{}

	class iterator;
	iterator begin()
	{
		return iterator(first);
	}
	iterator end()
	{
		return iterator(last);
	}
	iterator insert(iterator p, const Elem& v);
	iterator erase(iterator p);
	void push_back(const Elem& v)
	{
		Link<Elem>* p = std::make_unique<Link<Elem>>(v).release();
		if (last == first)
		{
			first = p;
		}
		else
		{
			last->prev->succ = p;
		}
		p->prev = last->prev;
		p->succ = last;
		last->prev = p;
		++sz;
	}
	void push_front(const Elem& v)
	{
		first = std::make_unique<Link<Elem>>(v, nullptr, first).release();
		if (first->succ != nullptr)
		{
			first->succ->prev = first;
		}
	}
	void pop_front();
	void pop_back();
	Elem& front()
	{
		return *first;
	}
	Elem& back();
	~list()
	{
		while (first != nullptr)
		{
			auto p = first->succ;
			delete first;
			first = p;
		}
	}
};

template<class Elem>
class list<Elem>::iterator
{
private:
	Link<Elem>* curr;
public:
	iterator(Link<Elem>* p) :
		curr{ p }
	{}
	iterator& operator++()
	{
		if (curr->succ == nullptr)
		{
			throw std::out_of_range("bad iterator _ out of range");
		}
		curr = curr->succ;
		return *this;
	}
	iterator& operator--()
	{
		if (curr->prev == nullptr)
		{
			throw std::out_of_range("bad iterator _ out of range");
		}
		curr = curr->prev;
		return *this;
	}
	Elem& operator*()
	{
		return curr->val;
	}
	const Elem& operator*() const
	{
		return curr->val;
	}
	Link<Elem>* operator->()
	{
		return curr;
	}
	Link<Elem>* ptr()
	{
		return curr;
	}
	bool operator==(const iterator& b) const
	{
		return curr == b.curr;
	}
	bool operator!=(const iterator& b) const
	{
		return curr != b.curr;
	}
};

#endif
