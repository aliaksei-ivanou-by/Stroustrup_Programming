#include <iostream>
#include <fstream>
#include <regex>
#include <sstream>
#include <map>
#include <numeric>
#include <iomanip>
#include "Task_23_10-11_students.h"

int main()
try
{
	std::string fileNameInput = "Task_23_10-11.txt";
	std::string fileNameOutput = "Task_23_10_result.txt";
	std::string fileNameOutputStatistics = "Task_23_11_result.txt";
	std::map<char, students> map;
	dataMerge(fileNameInput, fileNameOutput, map);
	getStatistics(map, fileNameOutputStatistics);
}
catch (const std::exception& e)
{
	std::cout << "Exception occured: " << e.what() << '\n';
	return 1;
}
catch (const char* ch)
{
	std::cout << ch << '\n';
	return 2;
}
catch (...)
{
	return 3;
}