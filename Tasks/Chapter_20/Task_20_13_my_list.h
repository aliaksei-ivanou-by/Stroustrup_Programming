#ifndef TASK_20_13_MY_LIST_H
#define TASK_20_13_MY_LIST_H

#ifndef TASK_20_13_STDAFX_H
#include "Task_20_13_stdafx.h"
#endif

template<class T>
T high(T first, T last)
{
	T high = first;
	for (T p = first; p != last; ++p)
	{
		if (*high < *p)
		{
			high = p;
		}
	}
	return high;
}

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
class my_list
{
private:
	Link<Elem>* first;
public:
	class iterator;
	my_list() :
		first{ nullptr }
	{}
	my_list(int n, Elem elem = Elem()) :
		first{ nullptr }
	{
		for (int i = 0; i < n; ++i)
		{
			first = new Link<Elem>(elem, nullptr, first);
			if (first->succ != nullptr)
			{
				first->succ->prev = first;
			}
		}
	}
	~my_list()
	{
		while (first)
		{
			pop_front();
		}
	}
	int size()
	{
		int sz = 0;
		for (iterator i = begin(); i != end(); ++i)
		{
			++sz;
		}
		return sz;
	}
	iterator begin()
	{
		return iterator(first);
	}
	const iterator begin() const
	{
		return iterator(first);
	}
	iterator end()
	{
		return iterator(nullptr);
	}
	const iterator end() const
	{
		return iterator(nullptr);
	}
	void push_back(const Elem& v)
	{
		iterator p = begin();
		while (p->succ)
		{
			++p;
		}
		p->succ = new Link<Elem>(v, p.ptr());
	}
	void push_front(const Elem& v)
	{
		first = new Link<Elem>(v, nullptr, first);
	}
	void pop_front()
	{
		Link<Elem>* p = first->succ;
		delete first;
		first = p;
	}
	Elem& front()
	{
		return first->val;
	}
};

template<class Elem>
class my_list<Elem>::iterator
{
private:
	Link<Elem>* curr;
public:
	iterator(Link<Elem>* p) :
		curr{ p }
	{}
	iterator& operator++()
	{
		curr = curr->succ;
		return *this;
	}
	iterator& operator--()
	{
		curr = curr->prev;
		return *this;
	}
	Elem& operator*()
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