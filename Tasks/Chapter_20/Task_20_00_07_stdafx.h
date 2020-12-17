#ifndef TASK_20_00_07_STDAFX_H
#define TASK_20_00_07_STDAFX_H

#include <iostream>
#include <string>
#include <vector>
#include <list>

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

void funcChar(const char myChar[])
{
	std::cout << "funcChar\n";
	std::cout << strlen(myChar) << " is myChar[] size\n";
	if (strcmp(myChar, "Hello") == 0)
	{
		std::cout << "myChar = 'Hello'\n";
	}
	switch (strcmp(myChar, "Howdy"))
	{
	case (-1):
	{
		std::cout << "myChar < 'Howdy'\n";
		break;
	}
	case (0):
	{
		std::cout << "myChar = 'Howdy'\n";
		break;
	}
	case (1):
	{
		std::cout << "myChar > 'Howdy'\n";
		break;
	}
	}
	char newChar[6];
	strcpy_s(newChar, myChar);
}

void funcVector(const std::vector<char>& myVector)
{
	std::cout << "funcVector\n";
	std::cout << myVector.size() << " is myVector size\n";
	if (my_strcmp(myVector, "Hello") == 0)
	{
		std::cout << "myVector = 'Hello'\n";
	}
	switch (my_strcmp(myVector, "Howdy"))
	{
	case (-1):
	{
		std::cout << "myVector < 'Howdy'\n";
		break;
	}
	case (0):
	{
		std::cout << "myVector = 'Howdy'\n";
		break;
	}
	case (1):
	{
		std::cout << "myVector > 'Howdy'\n";
		break;
	}
	}
	std::vector<char> newVector = myVector;
}

void funcList(const std::list<char>& myList)
{
	std::cout << "funcList\n";
	std::cout << myList.size() << " is myList size\n";
	if (my_strcmp(myList, "Hello") == 0)
	{
		std::cout << "myList = 'Hello'\n";
	}
	switch (my_strcmp(myList, "Howdy"))
	{
	case (-1):
	{
		std::cout << "myList < 'Howdy'\n";
		break;
	}
	case (0):
	{
		std::cout << "myList = 'Howdy'\n";
		break;
	}
	case (1):
	{
		std::cout << "myList > 'Howdy'\n";
		break;
	}
	}
	std::list<char> newList = myList;
}

void funcString(const std::string& myString)
{
	std::cout << "funcString\n";
	std::cout << myString.size() << " is myString size\n";
	if (myString == "Hello")
	{
		std::cout << "myString = 'Hello'\n";
	}
	if (myString < "Howdy")
	{
		std::cout << "myString < 'Howdy'\n";
	}
	std::string newString = myString;
}