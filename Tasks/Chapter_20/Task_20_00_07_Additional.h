#ifndef TASK_20_00_07_ADDITIONAL_H
#define TASK_20_00_07_ADDITIONAL_H

#ifndef TASK_20_00_07_STDAFX_H
#include "Task_20_00_07_stdafx.h"
#endif

template<class T>
int my_strcmp(const T& myClass, const std::string& word)
{
	int i = 0;
	for (auto p = myClass.begin(); p != myClass.end() && i < word.size(); ++p)
	{
		if (*p < word[i])
		{
			return -1;
		}
		if (*p > word[i])
		{
			return 1;
		}
		++i;
	}
	if (myClass.size() < word.size())
	{
		return -1;
	}
	if (myClass.size() > word.size())
	{
		return 1;
	}
	return 0;
}

void funcChar(const char myChar[]);
void funcVector(const std::vector<char>& myVector);
void funcList(const std::list<char>& myList);
void funcString(const std::string& myString);

#endif