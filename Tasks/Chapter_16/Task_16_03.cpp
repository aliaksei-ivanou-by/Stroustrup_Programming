#ifndef TASK_16_03_STDAFX_H
#include "Task_16_03_stdafx.h"
#endif

int main(int argc, char** argv)
try
{
	Image_Button win(Point(100, 100), 600, 600, "Image_Button");
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