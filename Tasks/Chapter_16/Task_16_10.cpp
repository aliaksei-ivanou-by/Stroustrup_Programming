#ifndef TASK_16_10_STDAFX_H
#include "Task_16_10_stdafx.h"
#endif

int main(int argc, char** argv)
try
{
	Choice_graph_funct win(Point(100, 100), xmax, ymax, "Choice_graph_funct");
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