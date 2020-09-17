#ifndef TASK_19_00_02_STDAFX
#include "Task_19_00_02_stdafx.h"
#endif

int main(int argc, char** argv)
try
{
	std::vector<int> v{ 1, 2, 3 };
	int s = 0;
	suspicious(v, s);
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