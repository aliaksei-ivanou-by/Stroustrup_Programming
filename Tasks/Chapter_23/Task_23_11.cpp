#ifndef TASK_23_11_STDAFX_H
#include "Task_23_11_stdafx.h"
#endif

int main()
try
{
	std::string fileNameInput = "Task_23_11.txt";
	std::string fileNameOutput = "Task_23_11_result.txt";
	std::string fileNameOutputStatistics = "Task_23_11_statistics.txt";
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