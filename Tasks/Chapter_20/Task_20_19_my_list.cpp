#include <iostream>

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
	Link<Elem>* last;
	int sz;
public:
	class iterator;
	my_list() :
		first{ nullptr },
		last{ first },
		sz{}
	{}
	my_list(int n, Elem elem = Elem()) :
		first{ new Link<Elem>() },
		last{ first },
		sz{ n }
	{
		for (int i = 0; i < n; ++i)
		{
			first = new Link<Elem>(elem, nullptr, first);
			first->succ->prev = first;
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
		return iterator(last);
	}
	const iterator end() const
	{
		return iterator(last);
	}
	iterator insert(iterator p, const Elem& v)
	{
		Link<Elem>* k = new Link<Elem>(v, p->prev);
		if (p->succ)
		{
			k->succ = p->succ->prev;
		}
		else
		{
			k->succ = last;
		}
		p->prev = k;
		if (k->prev)
		{
			k->prev->succ = k;
		}
		else
		{
			first = k;
		}
		++sz;
		return iterator(k);
	}
	void push_back(const Elem& v)
	{
		Link<Elem>* p = new Link<Elem>(v);
		if (first == nullptr)
		{
			first = new Link<Elem>();
			last = first;
		}
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
		Link<Elem>* p = new Link<Elem>(v);
		if (first == nullptr)
		{
			first = new Link<Elem>();
			last = first;
		}
		p->succ = first;
		first->prev = p;
		first = p;
		++sz;
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
	Elem& back()
	{
		return last->prev->val;
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

int main()
try
{
	my_list<int> myList;
	int n = 10;
	for (int i = n; i > 0; --i)
	{
		myList.push_front(i);
	}
	for (int i = n; i > 0; --i)
	{
		myList.push_back(i);
	}

	std::cout << '\n';
	for (auto i : myList)
	{
		std::cout << i << ' ';
	}
	std::cout << '\n';

	try
	{
		auto myIterator = myList.begin();
		--myIterator;
	}
	catch (std::out_of_range&)
	{
		std::cout << "Decrement from begin.\tError - Out of range\n";
	}

	try
	{
		auto myIterator = myList.end();
		++myIterator;
	}
	catch (std::out_of_range&)
	{
		std::cout << "Decrement from end.\tError - Out of range\n";
	}
}
catch (const std::exception& e)
{
	std::cout << "Exception occured: " << e.what() << '\n';
	return 1;
}
catch (...)
{
	return 2;
}