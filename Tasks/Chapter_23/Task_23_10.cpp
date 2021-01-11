#ifndef TASK_23_10_STDAFX_H
#include "Task_23_10_stdafx.h"
#endif

int main()
try
{
	std::string fileNameInput = "Task_23_10.txt";
	std::string fileNameOutput = "Task_23_10_result.txt";
	std::map<char, students> map;

	dataMerge(fileNameInput, fileNameOutput, map);
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