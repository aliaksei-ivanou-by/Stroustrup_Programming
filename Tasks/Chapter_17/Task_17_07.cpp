#include <iostream>
#include "std_lib_facilities.h"

char* resize(char* input, int length)
{
	if (!input)
	{
		return nullptr;
	}
	char* output = new char[length + 2];
	for (int i = 0; input[i]; ++i)
	{
		output[i] = input[i];
	}
	output[length] = '\0';
	delete[] input;
	return output;
}

int main()
try
{
	char* arr = new char[0]();
	*arr = 0;
	char exit = '!';
	char ch;
	unsigned long long i = 0;

	while (std::cin >> ch && ch != exit)
	{
		arr = resize(arr, i + 1);
		arr[i] = ch;
		arr[i + 1] = 0;
		++i;
	}

	std::cout << arr << '\n';
	delete[] arr;
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