#ifndef TASK_16_07_STDAFX_H
#include "Task_16_07_stdafx.h"
#endif

int main(int argc, char** argv)
try
{
	Flying_airplane* airplane = new Flying_airplane(Point(100, 100), 300, 300, "Flying_airplane");
	Fl::add_timeout(1.0, Flying_airplane::cb_fly, airplane);
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