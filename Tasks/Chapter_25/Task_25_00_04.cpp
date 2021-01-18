#include <iostream>

void infinite()
{
	unsigned char max = 160;
	for (signed char i = 0; i < max; ++i) // ranges of 'i' - [-128, 127]
	{
		std::cout << int(i) << '\n';
	}
}

int main()
try
{
	infinite();
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