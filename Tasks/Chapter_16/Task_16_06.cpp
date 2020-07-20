#ifndef TASK_16_06_STDAFX_H
#include "Task_16_06_stdafx.h"
#endif

int main(int argc, char** argv)
try
{
	Clock* clock = new Clock(Point(100, 100), 600, 600, "Clock");
	Fl::add_timeout(1.0, Clock::cb_run_clock, clock);
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