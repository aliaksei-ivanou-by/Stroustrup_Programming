#include <iostream>

int main()
try
{
	{
		while (true)
		{
			std::cout << "Hello, World!\n";
		}
	}
	{
		for (char i = 0; i < 128; ++i)
		{
			std::cout << "Hello, World!\n";
		}
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