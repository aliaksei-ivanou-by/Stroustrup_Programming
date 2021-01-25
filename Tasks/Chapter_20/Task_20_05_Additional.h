#ifndef TASK_20_05_ADDITIONAL_H
#define TASK_20_05_ADDITIONAL_H

#ifndef TASK_20_05_STDAFX_H
#include "Task_20_05_stdafx.h"
#endif

template<typename T>
std::istream& operator>>(std::istream& inputStream, std::vector<T>& vector)
{
	std::cout << "(Example : { 1 2 3 })\n";
	char ch;
	T temp;
	inputStream >> ch;
	while (true)
	{
		inputStream >> ch;
		if (inputStream && ch == '}')
		{
			return inputStream;
		}
		else
		{
			inputStream.unget();
		}
		inputStream >> temp;
		if (inputStream)
		{
			vector.push_back(temp);
		}
	}
	return inputStream;
}

template<typename T>
std::ostream& operator<<(std::ostream& outputStream, std::vector<T>& vector)
{
	outputStream << "{ ";
	for (auto& i : vector)
	{
		outputStream << i << ' ';
	}
	outputStream << "}";
	return outputStream;
}

#endif