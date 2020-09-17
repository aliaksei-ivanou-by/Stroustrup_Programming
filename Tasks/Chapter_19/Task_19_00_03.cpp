#ifndef TASK_19_00_03_STDAFX_H
#include "Task_19_00_03_stdafx.h"
#endif

int main(int argc, char** argv)
try
{
	std::cout << "v(100)\n";
	vector<int> v(100);
	std::cout << "v: size = " << v.size() << ", capacity = " << v.capacity() << '\n';
	std::cout << "v.reserve(200)\n";
	v.reserve(200);
	std::cout << "v: size = " << v.size() << ", capacity = " << v.capacity() << '\n';
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