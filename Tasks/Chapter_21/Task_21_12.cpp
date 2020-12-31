#ifndef TASK_21_12_STDAFX_H
#include "Task_21_12_stdafx.h"
#endif

int main(int argc, char** argv)
try
{
	Window_Order_request win;
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