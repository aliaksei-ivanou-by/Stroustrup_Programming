#ifndef TASK_20_00_03_STDAFX_H
#include "Task_20_00_03_stdafx.h"
#endif

int main()
try
{
	const int n = 10;
	int myArray1[n] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int* myArrayPtr1 = myArray1;
	std::cout << "myArrayPtr1 : ";
	for (size_t i = 0; i < n; ++i)
	{
		std::cout << myArrayPtr1[i] << ' ';
	}
	std::cout << '\n';

	int myArray2[n];
	int* myArrayPtr2 = myArray2;
	copy(myArrayPtr1, myArrayPtr1 + n, myArrayPtr2);

	std::cout << "myArrayPtr2 : ";
	for (size_t i = 0; i < n; ++i)
	{
		std::cout << myArrayPtr2[i] << ' ';
	}
	std::cout << '\n';
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