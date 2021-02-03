#pragma once
#include <iostream>
#include <assert.h>

template<typename T>
class Stack
{
private:
	T* stack;
	const int sz;
	int top;
public:
	Stack(int sizeMax = 10) :
		sz{ sizeMax }
	{
		stack = new T[sizeMax];
		top = 0;
	}
	Stack(const Stack<T>& stackOther):
		sz{ stackOther.size() }
	{
		stack = new T[sz];
		top = stackOther.getTop();
		for (int i = 0; i < top; ++i)
		{
			stack[i] = stackOther.getPtr()[i];
		}
	}
	~Stack()
	{
		delete[] stack;
	}
	Stack& operator=(const Stack& stackOther) = delete;
	inline void push(const T& value)
	{
		assert(top < sz);
		stack[top++] = value;
	}
	inline T& pop()
	{
		assert(top > 0);
		return stack[--top];
	}
	inline int size() const
	{
		return sz;
	}
	inline T* getPtr() const
	{
		return stack;
	}
	inline int getTop() const
	{
		return top;
	}
};