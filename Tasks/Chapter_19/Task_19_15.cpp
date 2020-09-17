#ifndef TASK_19_15_STDAFX_H
#include "Task_19_15_stdafx.h"
#endif

int main(int argc, char** argv)
try
{
	Window_HuntTheWumpus win;
	return gui_main();
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