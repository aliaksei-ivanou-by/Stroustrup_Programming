#ifndef TASK_21_07_STDAFX_H
#include "Task_21_07_stdafx.h"
#endif

int main()
try
{
	std::vector<int> vec;
	constexpr size_t vecSize = 10;
	for (size_t i = 0; i < vecSize; ++i)
	{
		vec.push_back(i * 5);
	}
	std::cout << "Vector is :\n";
	for (const auto& i : vec)
	{
		std::cout << i << ' ';
	}
	std::cout << '\n';

	int vecNumber = vec[rand() % vecSize];
	std::cout << "Number for find is " << vecNumber << '\n';

	if (myBinarySearch(vec.begin(), vec.end(), vecNumber))
	{
		std::cout << "Binary Search for number " << vecNumber << " : number is found!\n";
	}
	else
	{
		std::cout << "Binary Search for number " << vecNumber << " : number isn't found!\n";
	}
	

	std::list<std::string> li;
	constexpr size_t liSize = 10;
	for (size_t i = 0; i < liSize; ++i)
	{
		li.push_back(std::string(1, 65 + i));
	}

	std::cout << '\n';
	
	std::cout << "List is :\n";
	for (const auto& i : li)
	{
		std::cout << i << ' ';
	}
	std::cout << '\n';

	std::string liLetter = "B";
	std::cout << "Letter for find is " << liLetter << '\n';

	if (myBinarySearch(li.begin(), li.end(), liLetter))
	{
		std::cout << "Binary Search for letter " << liLetter << " : letter is found!\n";
	}
	else
	{
		std::cout << "Binary Search for letter " << liLetter << " : letter isn't found!\n";
	}
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