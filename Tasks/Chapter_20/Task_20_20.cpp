#ifndef TASK_20_20_STDAFX_H
#include "Task_20_20_stdafx.h"
#endif

int main()
try
{
	unsigned long long int N;
	std::cout << "Enter N : " << '\n';
	std::cin >> N;

	// Vector
	auto timeVectorStart = std::chrono::system_clock::now();
	std::vector<unsigned long long int> myVector;
	for (unsigned long long int i = 0; i < N; ++i)
	{
		auto myVectorIterator = myVector.begin();
		unsigned long long int temp = rand() & N;
		while (myVectorIterator != myVector.end() && *myVectorIterator <= temp)
		{
			++myVectorIterator;
		}
		myVector.insert(myVectorIterator, temp);
	}
	auto timeVectorFinish = std::chrono::system_clock::now();
	std::cout << "Time for vector is\t" <<
		std::chrono::duration_cast<std::chrono::milliseconds>(timeVectorFinish - timeVectorStart).count() << "ms";

	std::cout << "\n";

	// List
	auto timeListStart = std::chrono::system_clock::now();
	std::vector<unsigned long long int> myList;
	for (unsigned long long int i = 0; i < N; ++i)
	{
		auto myListIterator = myList.begin();
		unsigned long long int temp = rand() & N;
		while (myListIterator != myList.end() && *myListIterator <= temp)
		{
			++myListIterator;
		}
		myList.insert(myListIterator, temp);
	}
	auto timeListFinish = std::chrono::system_clock::now();
	std::cout << "Time for list is\t" <<
		std::chrono::duration_cast<std::chrono::milliseconds>(timeListFinish - timeListStart).count() << "ms";
	return 0;
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