#pragma once
#include <iostream>
#include "Task_27_List.h"

int main()
try
{
	List list;

	std::cout << "\npush_back 'Alex', 'John', 'Jack'\n";
	list.push_back(new Name("Alex"));
	list.push_back(new Name("John"));
	list.push_back(new Name("Jack"));
	list.print();

	std::cout << "\npush_front 'Jane', 'Leo', 'Diana'\n";
	list.push_front(new Name("Jane"));
	list.push_front(new Name("Leo"));
	list.push_front(new Name("Diana"));
	list.print();

	std::cout << "\nadvance & insert 'Paul'\n";
	auto it = advance(list.begin(), 2);
	list.insert(it, new Name("Paul"));
	list.print();

	std::cout << "\nerase 'begin()'\n";
	Link* l = list.erase(list.begin());
	list.print();
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
