#ifndef TASK_19_12_STDAFX_H
#include "Task_19_12_stdafx.h"
#endif

int main(int argc, char** argv)
try
{
	File_handle file{ "Task_19_12.txt" };
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