#ifndef TASK_20_14_STDAFX_H
#define TASK_20_14_STDAFX_H

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
	Link(const Elem& v = Elem(), Link* s = nullptr) :
		succ{ s },
		val{ v }
	{}
	Link* succ;
	Elem val;
};

template<class Elem>
class slist
{
public:
	slist() :
		first{ nullptr }
	{}
	Link<Elem>* first;

	class iterator;
	iterator begin()
	{
		return iterator(first);
	}
	iterator end()
	{
		return iterator(nullptr);
	}
	void push_front(const Elem& v)
	{
		first = std::make_unique<Link<Elem>>(v, first).release();
	}
	void pop_front()
	{
		Link<Elem>* temp = first->succ;
		delete first;
		first = temp;
	}
	Elem& front()
	{
		return *first;
	}
	~slist()
	{
		while (first)
		{
			pop_front();
		}
	}
};

template<class Elem>
class slist<Elem>::iterator
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