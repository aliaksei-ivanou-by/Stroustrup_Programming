#ifndef TASK_23_15_STDAFX_H
#include "Task_23_15_stdafx.h"
#endif

int main()
try
{
	std::string myString = R"(abcd \ abcd)";
	std::cout << myString << '\n';
	std::regex pat { R"(\)" };
	if (std::regex_search(myString, pat))
	{
		std::cout << "Found!\n";
	}
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