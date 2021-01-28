#ifndef TASK_19_10_STDAFX_H
#include "Task_19_10_stdafx.h"
#endif

struct myStruct
{
	myStruct():
		number{ 0 }
	{};
	myStruct(int numberToAdd):
		number{ numberToAdd }
	{}
	~myStruct()
	{}
	int number;
};

int main(int argc, char** argv)
try
{
	myStruct* ptr = new myStruct();
	my_unique_ptr<myStruct> ptr1(new myStruct(55));
	myStruct* ptr1Release = ptr1.release();
	std::cout << "*ptr1Release = " << ptr1Release << '\n';
	std::cout << "(*ptr1Release).number = " << (*ptr1Release).number << '\n';
	std::cout << "ptr1Release->number = " << ptr1Release->number << '\n';
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