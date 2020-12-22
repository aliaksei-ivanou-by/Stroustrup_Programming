#ifndef TASK_20_18_STDAFX_H
#include "Task_20_18_stdafx.h"
#endif

int main(int argc, char** argv)
try
{
	int n = 10;
	vector<int> myVector(n);
	for (int i = 0; i < n; ++i)
	{
		myVector[i] = i;
	}

	std::cout << "myVector size:\t" << myVector.size() << '\n';

	std::cout << "myVector" << '\t';
	for (const auto& i : myVector)
	{
		std::cout << i << ' ';
	}
	std::cout << '\n';

	try
	{
		auto myIterator = myVector.begin();
		--myIterator;
	}
	catch (std::out_of_range)
	{
		std::cout << "Decrement from begin.\tError - Out of range\n";
	}

	try
	{
		auto myIterator = myVector.end();
		++myIterator;
	}
	catch (std::out_of_range)
	{
		std::cout << "Decrement from end.\tError - Out of range\n";
	}

	try
	{
		auto myIterator = myVector.begin();
		auto temp = myIterator[23];
		std::cout << temp;
	}
	catch (std::out_of_range)
	{
		std::cout << "Out of range access.\tError - Out of range\n";
	}

	try
	{
		auto myIterator = myVector.begin();
		auto temp = myIterator[5];
		std::cout << *temp;
	}
	catch (std::out_of_range)
	{
		std::cout << "Out of range access.\tError - Out of range\n";
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