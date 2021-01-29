#include <iostream>
#include <bitset>
#include <iomanip>

template<class T>
void print(T value)
{
	std::cout << std::setw(20) << value << '\t' << std::bitset<32>(value) << '\n';
}

int main()
try
{
	std::cout << "Signed int:\n";
	signed int v1 = 0x0;
	print(v1);
	v1 = ~v1;
	print(v1);
	v1 = 0xaaaaaaaa;
	print(v1);
	v1 = 0x55555555;
	print(v1);
	v1 = 0xcccccccc;
	print(v1);
	v1 = 0x33333333;
	print(v1);
	v1 = 0xff00ff00;
	print(v1);

	std::cout << "\n\n";

	std::cout << "Unsigned int:\n";
	unsigned int v2 = 0x0;
	print(v2);
	v2 = ~v2;
	print(v2);
	v2 = 0xaaaaaaaa;
	print(v2);
	v2 = 0x55555555;
	print(v2);
	v2 = 0xcccccccc;
	print(v2);
	v2 = 0x33333333;
	print(v2);
	v2 = 0xff00ff00;
	print(v2);
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