#ifndef TASK_19_16_STDAFX_H
#include "Task_19_16_stdafx.h"
#endif

int main(int argc, char** argv)
try
{
	std::cout << "sizeof(vectorShort<int>\t\t" << sizeof(vectorShort<int>) << '\n';
	std::cout << "sizeof(int*)\t\t\t" << sizeof(int*);

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