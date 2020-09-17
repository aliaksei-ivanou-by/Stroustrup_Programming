#ifndef TASK_19_00_04_STRUCT_H
#define TASK_19_00_04_STRUCT_H

#ifndef TASK_19_00_04_STDAFX_H
#include "Task_19_00_04_stdafx.h"
#endif

template<typename T>
struct S
{
private:
	T value;
public:
	S(T n):
		value(n)
	{}
	T& get()
	{
		return value;
	}
	const T& get() const
	{
		return value;
	}
	void set(const T& n)
	{
		value = n;
	}
	T& operator=(const T& element)
	{
		value = element;
		return value;
	}
};

template<class T>
void readValue(T& value)
{
	std::cin >> value;
}

template<class T>
std::ostream& operator<<(std::ostream& outputStream, const std::vector<T>& elements)
{
	outputStream << "{ ";
	for (size_t i = 0; i < elements.size(); ++i)
	{
		outputStream << elements[i];
		if (i < elements.size() - 1)
		{
			outputStream << ',';
		}
		outputStream << ' ';
	}
	outputStream << "}";
	return outputStream;
}

template<class T>
std::istream& operator>>(std::istream& inputStream, std::vector<T>& elements)
{
	char ch1;
	char ch2;
	T temp;
	std::vector<T> elementsTemp;
	inputStream >> ch1;
	if (!inputStream)
	{
		return inputStream;
	}
	if (ch1 != '{')
	{
		inputStream.clear(std::ios_base::failbit);
		return inputStream;
	}
	while (std::cin >> temp >> ch2 && ch2 == ',')
	{
		elementsTemp.push_back(temp);
	}
	if (ch2 != '}')
	{
		inputStream.clear(std::ios_base::failbit);
		return inputStream;
	}
	elementsTemp.push_back(temp);
	elements = elementsTemp;
}

template<class T>
std::istream& operator>>(std::istream& inputStream, S<T>& elements)
{
	T elementsTemp;
	std::cin >> elementsTemp;
	if (!inputStream)
	{
		return inputStream;
	}
	elements = elementsTemp;
	return inputStream;
}

#endif