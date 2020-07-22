#include <iostream>

int main()
try
{
	int a1 = 0;
	int b1 = 0;
	std::cout << "Stack : \n";
	std::cout << &a1 << '\n' << &b1 << '\n';
	int diff1 = &b1 - &a1;
	if (diff1 > 0)
	{
		std::cout << "Stack grows up\n";
	}
	else
	{
		std::cout << "Stack grows down\n";
	}

	std::cout << '\n';

	int* a2 = new int();
	int* b2 = new int();
	std::cout << "Heap : \n";
	std::cout << a2 << '\n' << b2 << '\n';
	int diff2 = b2 - a2;
	if (diff2 > 0)
	{
		std::cout << "Heap grows up\n";
	}
	else
	{
		std::cout << "Heap grows down\n";
	}
	delete a2;
	delete b2;
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