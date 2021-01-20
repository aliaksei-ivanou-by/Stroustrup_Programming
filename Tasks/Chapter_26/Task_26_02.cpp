#ifndef TASK_26_02_STDAFX_H
#include "Task_26_02_stdafx.h"
#endif

int main()
try
{
	{
		std::string fileName{ "Task_26_02_double.txt" };
		std::cout << fileName << '\n';
		std::ifstream inputFileStream{ fileName };
		unsigned int errors = test<double>(inputFileStream);
		std::cout << "Errors: " << errors << '\n';
	}
	std::cout << "\n\n";
	{
		std::string fileName{ "Task_26_02_string.txt" };
		std::cout << fileName << '\n';
		std::ifstream inputFileStream{ fileName };
		unsigned int errors = test<double>(inputFileStream);
		std::cout << "Errors: " << errors << '\n';
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