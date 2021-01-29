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
		first{ new Link<Elem>() },
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
	my_list<int> list1;
	std::cout << " 0 elements list size: " << list1.size() << '\n';
	my_list<int> list2(10);
	std::cout << "10 elements list size: " << list2.size() << '\n';

	my_list<int> list3;
	list3.push_front(1);
	list3.push_front(2);
	list3.push_front(3);
	list3.push_back(4);
	list3.push_back(5);
	list3.push_back(6);
	for (auto& i : list3)
	{
		std::cout << i << ' ';
	}
	std::cout << '\n';
	auto iterator = list3.begin();
	++iterator;
	list3.insert(iterator, 55);
	for (auto& i : list3)
	{
		std::cout << i << ' ';
	}
	std::cout << '\n';

	my_list<int> listHigh;
	int number;
	while (std::cin >> number)
	{
		listHigh.push_back(number);
	}
	auto p = high(listHigh.begin(), listHigh.end());
	std::cout << "High value of listHigh is " << *p << '\n';
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