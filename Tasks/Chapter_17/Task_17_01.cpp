#include <iostream>

int main()
try
{
	int* ptr = new int(0);
	std::cout << "ptr = " << ptr << '\n';
	std::cout << "ptr + 1 = " << &ptr[1] << '\n';
	delete ptr;
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