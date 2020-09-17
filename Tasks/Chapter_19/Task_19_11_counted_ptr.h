#ifndef TASK_19_11_COUNTED_PTR_H
#define TASK_19_11_COUNTED_PTR_H

#ifndef TASK_19_11_STDAFX_H
#include "Task_19_11_stdafx.h"
#endif

template<typename T>
class counted_ptr
{
private:
	T* pointer;
	unsigned int* counter;
public:
	counted_ptr(const T& number):
		pointer{ new T{ number } },
		counter{ new unsigned int {1} }
	{
		std::cout << "Constructor\n";
	}
	void reset()
	{
		pointer = nullptr;
		counter = nullptr;
	}
	T operator*()
	{
		return *pointer;
	}
	T* operator->()
	{
		return pointer;
	}
	counted_ptr(const counted_ptr& countedPtr):
		pointer{ countedPtr.pointer },
		counter{ countedPtr.counter }
	{
		++(*counter);
		std::cout << "Copy Constructor\tcounter++\n";
	}
	counted_ptr(counted_ptr&& countedPtr):
		pointer{ countedPtr.pointer },
		counter{ countedPtr.counter }
	{
		countedPtr.reset();
		std::cout << "Move Constructor\n";
	}
	counted_ptr& operator=(const counted_ptr& countedPtr)
	{
		if (&countedPtr = this)
		{
			return *this;
		}
		--(*counter);
		pointer = countedPtr.pointer;
		counter = countedPtr.counter;
		++(*counter);
		std::cout << "Copy operator=\n";
	}
	counted_ptr& operator=(counted_ptr&& countedPtr)
	{
		pointer = countedPtr.pointer;
		counter = countedPtr.counter;
		countedPtr.reset();
		std::cout << "Move operator=\n";
	}
	~counted_ptr()
	{
		std::cout << "Destructor\n";
		if (counter != nullptr)
		{
			--* counter;
			std::cout << "counter--\n";
			if (*counter == 0)
			{
				delete pointer;
				delete counter;
			}
		}
	}
};

#endif