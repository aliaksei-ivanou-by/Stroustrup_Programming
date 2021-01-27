#ifndef TASK_23_06_STDAFX_H
#include "Task_23_06_stdafx.h"
#endif

int main()
try
{
	std::string fileName = "Task_23_06.txt";
	std::ifstream inputFileStream{ fileName };
	if (!inputFileStream)
	{
		throw std::runtime_error("Can't read file");
	}

	int lineno = 0;
	std::string line;
	while (inputFileStream)
	{
		++lineno;
		std::getline(inputFileStream, line);
		if (findDates(line))
		{
			std::cout << lineno << ": " << line << '\n';
		}
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