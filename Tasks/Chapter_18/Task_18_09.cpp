#include <iostream>

static int a1 = 0;
static int b1 = 0;

int main()
try
{
	std::cout << "Static : \n";
	std::cout << &a1 << '\n' << &b1 << '\n';
	int diff1 = &b1 - &a1;
	if (diff1 > 0)
	{
		std::cout << "Static grows up\n";
	}
	else
	{
		std::cout << "Static grows down\n";
	}

	std::cout << '\n';

	int a2 = 0;
	int b2 = 0;
	std::cout << "Stack : \n";
	std::cout << &a2 << '\n' << &b2 << '\n';
	int diff2 = &b2 - &a2;
	if (diff2 > 0)
	{
		std::cout << "Stack grows up\n";
	}
	else
	{
		std::cout << "Stack grows down\n";
	}

	std::cout << '\n';

	int* a3 = new int();
	int* b3 = new int();
	std::cout << "Heap : \n";
	std::cout << a3 << '\n' << b3 << '\n';
	int diff3 = b3 - a3;
	if (diff3 > 0)
	{
		std::cout << "Heap grows up\n";
	}
	else
	{
		std::cout << "Heap grows down\n";
	}
	delete a3;
	delete b3;

	std::cout << '\n';

	int* a4 = new int[2];
	std::cout << "Array in heap : \n";
	for (int i = 0; i < 2; ++i)
	{
		a4[i] = 0;
		std::cout << &a4[i] << '\n';
	}
	int diff4 = &a4[1] - &a4[0];
	if (diff4 > 0)
	{
		std::cout << "Array in heap grows up\n";
	}
	else
	{
		std::cout << "Array in heap grows down\n";
	}

	std::cout << '\n';

	int a5[2];
	std::cout << "Array in stack : \n";
	for (int i = 0; i < 2; ++i)
	{
		a5[i] = 0;
		std::cout << &a5[i] << '\n';
	}
	int diff5 = &a5[1] - &a5[0];
	if (diff5 > 0)
	{
		std::cout << "Array in stack grows up\n";
	}
	else
	{
		std::cout << "Array in stack grows down\n";
	}
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