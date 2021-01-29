#include <iostream>

using namespace std;
int main()
try
{
	int n = 0;
	for (int i = 1; ; ++n)
	{
		std::cout << n << '\t' << (i << n) << '\n';
		if ((i << n) < (i << (n - 1)))
		{
			break;
		}
	}
	std::cout << "\n\n";
	std::cout << "Number of bits in INT is "<< n + 1 << '\n';

	char ch = -1;
	if (ch == -1)
	{
		std::cout << "CHAR is signed\n";
	}
	else
	{
		std::cout << "CHAR is unsigned\n";
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