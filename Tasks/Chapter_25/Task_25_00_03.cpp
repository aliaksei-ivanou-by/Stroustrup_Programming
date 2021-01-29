#include <iostream>
#include <bitset>

int main()
try
{
	for (int i; std::cin >> i; )
	{
		std::cout << std::dec << i << " = " <<
			std::hex << std::showbase << i << " = " <<
			std::bitset<8 * sizeof(int)>(i) << '\n';
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