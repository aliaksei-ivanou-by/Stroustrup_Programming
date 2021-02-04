#include <iostream>
#include <vector>
#include <cmath>
#include "Task_25_Calculator.h"

int main()
try
{
	calculate();
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