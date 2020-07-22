#include <iostream>
#include "std_lib_facilities.h"

int main()
try
{
	int count = 0;
	while (true)
	{
		int key = 10000;
		int* arr = new int[key];
		std::cout << sizeof(int) << '\n';
		std::cout << count * sizeof(int) * key / 1073741824.0 << " GB\n";
		++count;
	}
	// my maximum is 25.4953 GB
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