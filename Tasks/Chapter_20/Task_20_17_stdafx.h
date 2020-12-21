#ifndef TASK_20_17_STDAFX_H
#define TASK_20_17_STDAFX_H

#include <iostream>
#include <vector>

#endif

template<typename Elem>
class ownership_vector
{
private:
	std::vector<Elem*> vec;
	std::vector<Elem*> owned;
public:
	ownership_vector():
		vec{},
		owned{}
	{}
	~ownership_vector()
	{
		for (size_t i = 0; i < owned.size(); ++i)
		{
			delete owned[i];
		}
	}
	void push_back(Elem& elem)
	{
		vec.push_back(&elem);
	}
	void push_back(Elem* elem)
	{
		vec.push_back(elem);
		owned.push_back(elem);
	}
	size_t size()
	{
		return vec.size();
	}
	size_t size_owned()
	{
		return owned.size();
	}
	Elem& operator[](int i)
	{
		return *vec[i];
	}
	Elem& operator[](int i) const
	{
		return *vec[i];
	}
};