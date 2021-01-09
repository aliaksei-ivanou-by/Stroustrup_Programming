#ifndef TASK_23_12_STDAFX_H
#include "Task_23_12_stdafx.h"
#endif

int main()
try
{
	std::string fileName1 = "Task_23_12.txt";
	std::ifstream inputFileStream{ fileName1 };
	if (!inputFileStream)
	{
		throw ("Can't read file");
	}
	std::string fileName2 = "Task_23_12_result.txt";
	std::ofstream outputFileStream{ fileName2 };
	for (std::string line; std::getline(inputFileStream, line); )
	{
		outputFileStream << dateToDefault(line) << '\n';
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