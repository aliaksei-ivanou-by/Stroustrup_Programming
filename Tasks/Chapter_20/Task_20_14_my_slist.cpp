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
class my_slist
{
private:
	Link<Elem>* first;
public:
	class iterator;
	my_slist() :
		first{ nullptr }
	{}
	my_slist(int n, Elem elem = Elem()) :
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
	~my_slist()
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
class my_slist<Elem>::iterator
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

int main()
try
{
	my_slist<int> myList;
	int number;
	while (std::cin >> number)
	{
		myList.push_front(number);
	}
	auto p = high(myList.begin(), myList.end());
	std::cout << "High value of myList is " << *p;
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