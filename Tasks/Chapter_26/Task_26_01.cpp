#ifndef TASK_26_01_STDAFX_H
#include "Task_26_01_stdafx.h"
#endif

int main()
try
{
	std::string fileName{ "Task_26_01.txt" };
	std::ifstream inputFileStream{ fileName };
	unsigned int errors = test(inputFileStream);
	std::cout << "Errors: " << errors << '\n';

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