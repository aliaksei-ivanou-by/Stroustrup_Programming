#ifndef TASK_20_18_VECTOR_H
#define TASK_20_18_VECTOR_H

#ifndef TASK_20_18_STDAFX_H
#include "Task_20_18_stdafx.h"
#endif

template<class T>
class vector
{
private:
	size_t sz;
	T* elem;
	size_t space;
public:
	class iterator;
	vector() :
		sz{ 0 },
		elem{ nullptr },
		space{ 0 }
	{}
	explicit vector(size_t n) :
		sz{ n },
		elem{ std::make_unique<T[]>(n).release() },
		space{ n }
	{
		for (auto i = begin(); i != end(); ++i)
		{
			*i = T();
		}
	}
	vector(const vector& v) :
		sz{ v.sz },
		elem{ std::make_unique<T[]>(v.sz).release() },
		space{ v.sz }
	{
		std::copy(v.elem, v.elem + v.sz, elem);
	}
	T& operator[](int n)
	{
		return elem[n];
	}
	T& operator[](int n) const
	{
		return elem[n];
	}
	iterator begin()
	{
		return iterator(elem, elem, sz);
	}
	iterator begin() const
	{
		return iterator(elem, elem, sz);
	}
	iterator end()
	{
		return iterator(elem + sz, elem, sz);
	}
	iterator end() const
	{
		return iterator(elem + sz, elem, sz);
	}
	size_t size() const
	{
		return sz;
	}
	size_t capacity() const
	{
		return space;
	}
};

template<typename T>
class vector<T>::iterator
{
private:
	T* curr;
	T* first;
	T* last;
public:
	iterator(T* p, T* elem, size_t sz):
		curr{ p },
		first{ elem },
		last{ elem + sz }
	{}
	iterator& operator++()
	{
		if (curr == last)
		{
			throw std::out_of_range("bad iterator _ out of range");
		}
		++curr;
		return *this;
	}
	iterator& operator--()
	{
		if (curr == first)
		{
			throw std::out_of_range("bad iterator _ out of range");
		}
		--curr;
		return *this;
	}
	T& operator*()
	{
		return *curr;
	}
	T& operator*() const
	{
		return *curr;
	}
	bool operator==(const iterator& other) const
	{
		return curr == other.curr;
	}
	bool operator!=(const iterator& other) const
	{
		return curr != other.curr;
	}
	auto operator[](int n)
	{
		auto myCurr = curr + n;
		if (myCurr < first || myCurr > last)
		{
			throw std::out_of_range("bad iterator _ out of range");
		}
		return myCurr;
	}
	auto operator[](int n) const
	{
		auto myCurr = curr + n;
		if (myCurr < first || myCurr > last)
		{
			throw std::out_of_range("bad iterator _ out of range");
		}
		return myCurr;
	}
};

#endif