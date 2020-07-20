#ifndef TASK_16_02_STDAFX_H
#include "Task_16_02_stdafx.h"
#endif

int main(int argc, char** argv)
try
{
	Button_board bb(Point(100, 100), 600, 600, "Button_board", 4, 4);
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