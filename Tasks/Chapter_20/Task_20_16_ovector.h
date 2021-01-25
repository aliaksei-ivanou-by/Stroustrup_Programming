#ifndef TASK_20_16_OVECTOR_H
#define TASK_20_16_OVECTOR_H

#ifndef TASK_20_16_STDAFX_H
#include "Task_20_16_stdafx.h"
#endif

template<typename Elem>
class ovector
{
private:
	std::vector<Elem*> vec;
public:
	ovector() :
		vec{}
	{}
	~ovector()
	{
		for (auto i = begin(); i < end(); ++i)
		{
			delete* i;
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

#endif