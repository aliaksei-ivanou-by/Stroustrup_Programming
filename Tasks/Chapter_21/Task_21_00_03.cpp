#ifndef TASK_21_00_03_STDAFX_H
#include "Task_21_00_03_stdafx.h"
#endif

int main()
try
{
	std::vector<Record> myVector;
	myVector.push_back(Record{ 1.1, 1 });
	myVector.push_back(Record{ 2.2, 2 });
	myVector.push_back(Record{ 3.3, 3 });
	myVector.push_back(Record{ 4.4, 4 });
	f(myVector);
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