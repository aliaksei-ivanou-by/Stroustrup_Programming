#ifndef TASK_19_09_STDAFX_H
#include "Task_19_09_stdafx.h"
#endif

int main(int argc, char** argv)
try
{
	vector<int> myVector1(5);
	myVector1[0] = 0;
	myVector1[1] = 1;
	myVector1[2] = 2;
	myVector1[3] = 3;
	myVector1[4] = 4;
	myVector1.push_back(5);
	myVector1.push_back(6);
	std::cout << "myVector1 : ";
	for (int i = 0; i < myVector1.size(); ++i)
	{
		std::cout << myVector1[i] << ' ';
	}
	std::cout << '\n';
	vector<int> myVector2 = myVector1;
	std::cout << "myVector2 : ";
	for (int i = 0; i < myVector2.size(); ++i)
	{
		std::cout << myVector2[i] << ' ';
	}
	std::cout << '\n';
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