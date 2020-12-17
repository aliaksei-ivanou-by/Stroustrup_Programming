#ifndef TASK_20_00_07_STDAFX_H
#include "Task_20_00_07_stdafx.h"
#endif

int main()
try
{
	char myChar[] = "Hello";
	funcChar(myChar);
	std::cout << '\n';

	std::vector<char> myVector;
	myVector.push_back('H');
	myVector.push_back('e');
	myVector.push_back('l');
	myVector.push_back('l');
	myVector.push_back('o');
	funcVector(myVector);
	std::cout << '\n';

	std::list<char> myList;
	myList.push_back('H');
	myList.push_back('e');
	myList.push_back('l');
	myList.push_back('l');
	myList.push_back('o');
	funcList(myList);
	std::cout << '\n';

	std::string myString = "Hello";
	funcString(myString);
}
catch (const std::exception& e)
{
	std::cout << "Exception occured: " << e.what() << '\n';
	return 1;
}
catch (...)
{
	return 2;
}