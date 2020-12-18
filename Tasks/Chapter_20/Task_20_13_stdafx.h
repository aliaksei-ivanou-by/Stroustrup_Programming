#ifndef TASK_20_13_STDAFX_H
#define TASK_20_13_STDAFX_H

#include <iostream>

#endif

template<class Iterator>
Iterator high(Iterator first, Iterator last)
{
	Iterator high = first;
	for (Iterator p = first; p != last; ++p)
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
	Link(const Elem& v = Elem(), Link* p = nullptr, Link* s = nullptr):
		prev(p),
		succ(s),
		val(v)
	{}
	Link* prev;
	Link* succ;
	Elem val;
};

template<class Elem>
class list
{
public:
	list():
		first( nullptr )
	{}
	Link<Elem>* first;
	Link<Elem>* last;

	class iterator;
	iterator begin()
	{
		return iterator(first);
	}
	iterator end()
	{
		return iterator(nullptr);
	}
	iterator insert(iterator p, const Elem& v);
	iterator erase(iterator p);
	void push_back(const Elem& v);
	void push_front(const Elem& v)
	{
		first = new Link<Elem>(v, nullptr, first);
	}
	void pop_front();
	void pop_back();
	Elem& front()
	{
		return *first;
	}
	Elem& back();
};

template<class Elem>
class list<Elem>::iterator
{
private:
	Link<Elem>* curr;
public:
	iterator(Link<Elem>* p):
		curr(p)
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
	bool operator==(const iterator& b) const
	{
		return curr == b.curr;
	}
	bool operator!=(const iterator& b) const
	{
		return curr != b.curr;
	}
};