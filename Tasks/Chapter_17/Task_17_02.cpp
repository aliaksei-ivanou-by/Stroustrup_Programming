#include <iostream>
#include <cmath>

int main()
try
{
	// int
	int* ptr_int = new int[2];
	ptr_int[0] = 0;
	ptr_int[1] = 0;
	std::cout << "int size = " << abs(reinterpret_cast<int>(&ptr_int[1]) - reinterpret_cast<int>(&ptr_int[0])) << '\n';
	std::cout << "sizeof(int) = " << sizeof(int) << '\n';
	std::cout << '\n';

	// double
	double* ptr_double = new double[2];
	ptr_double[0] = 0;
	ptr_double[1] = 0;
	std::cout << "double size = " << abs(reinterpret_cast<int>(&ptr_double[1]) - reinterpret_cast<int>(&ptr_double[0])) << '\n';
	std::cout << "sizeof(double) = " << sizeof(double) << '\n';
	std::cout << '\n';

	// bool
	bool* ptr_bool = new bool[2];
	ptr_bool[0] = 0;
	ptr_bool[1] = 0;
	std::cout << "bool size = " << abs(reinterpret_cast<int>(&ptr_bool[1]) - reinterpret_cast<int>(&ptr_bool[0])) << '\n';
	std::cout << "sizeof(bool) = " << sizeof(bool) << '\n';
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