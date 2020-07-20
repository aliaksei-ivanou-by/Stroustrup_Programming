#ifndef TASK_14_16_CONTROLLER_SHOW_H
#include "Task_14_16_stdafx.h"
#include "Task_14_16_Controller_Show.h"
#endif

void Controller_Show::show() const
{
	std::cout << "Status is " << status << '\n';
	std::cout << "Level is " << level << '\n';
}
