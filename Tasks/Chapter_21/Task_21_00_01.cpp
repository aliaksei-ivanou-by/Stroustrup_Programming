#ifndef TASK_21_00_01_STDAFX_H
#include "Task_21_00_01_stdafx.h"
#endif

int main()
try
{
	std::vector<int> myVector;
	int n;
	std::cin >> n;
	srand(time(NULL));
	for (int i = 0; i < n; ++i)
	{
		myVector.push_back(rand() % 100);
	}
	std::cout << "MyVector :\n";
	for (const auto& i : myVector)
	{
		std::cout << i << ' ';
	}
	std::cout << '\n';
	int number = rand() % n;
	std::cout << "Number is " << number << '\n';
	auto result1 = find1(myVector.begin(), myVector.end(), myVector[number]);
	auto result2 = find2(myVector.begin(), myVector.end(), myVector[number]);
	std::cout << "Find1\t" << *result1 << '\t' << &*find1(myVector.begin(), myVector.end(), myVector[number]) << '\n';
	std::cout << "Find2\t" << *result2 << '\t' << &*find2(myVector.begin(), myVector.end(), myVector[number]) << '\n';
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