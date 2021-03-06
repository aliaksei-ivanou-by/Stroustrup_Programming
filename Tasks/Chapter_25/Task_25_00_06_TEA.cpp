#include <iostream>
#include <fstream>
#include <iomanip>
#include "Task_25_TEA.h"

int main()
try
{
	std::string infile("Task_25_00_06_input.txt");
	std::string outfile("Task_25_00_06_output.txt");
	std::string key("bs");

	messageReceive(infile, outfile, key);
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