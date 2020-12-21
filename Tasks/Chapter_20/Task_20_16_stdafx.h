#ifndef TASK_20_16_STDAFX_H
#define TASK_20_16_STDAFX_H

#include <iostream>
#include <vector>

#endif

template<typename Elem>
class ovector
{
private:
	std::vector<Elem*> vec;
public:
	ovector():
		vec{ }
	{}
	~ovector()
	{
		for (auto i = begin(); i < end(); ++i)
		{
			delete *i;
		}
	}
	auto begin()
	{
		return vec.begin();
	}
	auto begin() const
	{
		return vec.begin();
	}
	auto end()
	{
		return vec.end();
	}
	auto end() const
	{
		return vec.end();
	}
	size_t size()
	{
		return vec.size();
	}
	size_t capacity()
	{
		return vec.capacity();
	}
	void push_back(Elem* elem)
	{
		vec.push_back(elem);
	}
	Elem& operator[](int n)
	{
		return *vec[n];
	}
	Elem& operator[](int n) const
	{
		return *vec[n];
	}
};