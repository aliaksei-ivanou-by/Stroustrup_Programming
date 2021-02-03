#include <iostream>
#include "Task_25_Pool.h"

int main()
try
{
	constexpr int size = 1000;
	vector<int, size> vec;
	std::cout << "Empty vector\n";
	vec.print();

	vec.pop_back();

	for (auto i = 0; i < size; ++i)
	{
		vec.push_back(i);
	}
	std::cout << "Full vector\n";
	vec.print();
	
	vec.pop_back();
	vec.push_back(999);
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
