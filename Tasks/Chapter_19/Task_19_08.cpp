#ifndef TASK_19_08_STDAFX_H
#include "Task_19_08_stdafx.h"
#endif

int main(int argc, char** argv)
try
{
	vector<int> v1;
	v1.push_back(1);
	std::cout << "v1: \tsize = " << v1.size();
	std::cout << "\tcapacity = " << v1.capacity() << '\n';

	vector<int> v2(5);
	std::cout << "v2: \tsize = " << v2.size();
	std::cout << "\tcapacity = " << v2.capacity() << '\n';

	vector<int> v3(100);
	std::cout << "v3: \tsize = " << v3.size();
	std::cout << "\tcapacity = " << v3.capacity() << '\n';
	v3.reserve(200);
	std::cout << "v3: \tsize = " << v3.size();
	std::cout << "\tcapacity = " << v3.capacity() << '\n';
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