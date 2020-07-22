#include <iostream>
#include "std_lib_facilities.h"

int main()
try
{
	char* ch = new char[0];
	char c;
	
	int i = 0;
	while (std::cin >> c && c != '!')
	{
		ch[i] = c;
		++i;
	}

	for (int i = 0; ch[i]; ++i)
	{
		std::cout << ch[i] << ' ';
	}
	std::cout << '\n';
	delete[] ch;
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