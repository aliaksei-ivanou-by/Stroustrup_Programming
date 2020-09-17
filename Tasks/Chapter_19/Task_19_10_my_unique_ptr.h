#ifndef TASK_19_10_MY_UNIQUE_PTR_H
#define TASK_19_10_MY_UNIQUE_PTR_H

#ifndef TASK_19_10_STDAFX_H
#include "Task_19_10_stdafx.h"
#endif

template<typename T>
class my_unique_ptr
{
private:
	T* pointer;
public:
	explicit my_unique_ptr(T* pointerToAdd):
		pointer{ pointerToAdd }
	{
		std::cout << "Constructor of my_unique_ptr\n";
	}
	~my_unique_ptr()
	{
		std::cout << "Destructor of my_unique_ptr\n";
		delete pointer;
	}
	T* release()
	{
		T* temp = pointer;
		pointer = nullptr;
		return temp;
	}
	T& operator*()
	{
		return *pointer;
	}
	T& operator->()
	{
		return pointer;
	}
};

#endif