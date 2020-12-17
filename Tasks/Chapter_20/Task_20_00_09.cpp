#ifndef TASK_20_00_09_STDAFX_H
#include "Task_20_00_09_stdafx.h"
#endif

int main()
try
{
	// 1
	constexpr int size = 10;
	int myInt[size];
	for (int i = 0; i < size; ++i)
	{
		myInt[i] = i;
	}
	print(myInt, "myInt");

	// 2
	std::vector<int> myVector(size);
	std::copy(myInt, myInt + size, myVector.begin());
	print(myVector, "myVector");

	// 3
	std::list<int> myList(size);
	std::copy(myInt, myInt + size, myList.begin());
	print(myList, "myList");

	// 4
	int myInt2[size];
	for (int i = 0; i < size; ++i)
	{
		myInt2[i] = myInt[i];
	}
	print(myInt2, "myInt2");
	std::vector<int> myVector2 = myVector;
	print(myVector2, "myVector2");
	std::list<int> myList2 = myList;
	print(myList2, "myList2");

	// 5
	for (int i = 0; i < size; ++i)
	{
		myInt2[i] = myInt[i] + 2;
	}
	print(myInt2, "myInt2");
	for (auto& i : myVector2)
	{
		i += 3;
	}
	print(myVector2, "myVector2");
	for (auto& i : myList2)
	{
		i += 5;
	}
	print(myList2, "myList2");

	// 7
	myCopy(myInt2, myInt2 + size, myVector2.begin());
	print(myInt2, "myInt2");
	print(myVector2, "myVector2");
	myCopy(myList2.begin(), myList2.end(), myInt2);
	print(myList2, "myList2");
	print(myInt2, "myInt2");

	// 8
	auto myVector2HasNumber3 = std::find(myVector2.begin(), myVector2.end(), 3);
	if (myVector2HasNumber3 != myVector2.end())
	{
		std::cout << "Number 3 is found in myVector2 at " <<
			std::distance(myVector2.begin(), myVector2HasNumber3) << '\n';
	}
	else
	{
		std::cout << "Number 3 isn't found in myVector2\n";
	}
	auto myList2HasNumber27 = std::find(myList2.begin(), myList2.end(), 27);
	if (myList2HasNumber27 != myList2.end())
	{
		std::cout << "Number 27 is found in myList2 at " <<
			std::distance(myList2.begin(), myList2HasNumber27) << '\n';
	}
	else
	{
		std::cout << "Number 27 isn't found in myList2\n";
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