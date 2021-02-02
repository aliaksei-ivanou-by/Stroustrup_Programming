#include <iostream>

int main()
try
{
	std::cout << "C++ realization\n";
	std::cout << "\tmemory management with constructor and destructor - easier than C realiation\n";
	std::cout << "\tmember functions - less parametres and less errors\n";

	std::cout << "C realization\n";
	std::cout << "\tmanual memory management - more difficult than C++ realiation\n";
	std::cout << "\tall functions are general - more parametres and more errors\n";
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
