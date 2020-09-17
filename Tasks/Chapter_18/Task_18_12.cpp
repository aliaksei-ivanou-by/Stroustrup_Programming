#ifndef TASK_18_12_STDAFX_H
#include "Task_18_12_stdafx.h"
#endif

int main()
try
{
	game_hunt_the_wumpus();
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