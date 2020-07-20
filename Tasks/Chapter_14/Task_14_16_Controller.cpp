#ifndef TASK_14_16_CONTROLLER_H
#include "Task_14_16_stdafx.h"
#include "Task_14_16_Controller.h"
#endif

void Controller::on()
{
	status = true;
}

void Controller::off()
{
	status = false;
}

void Controller::set_level(int l)
{
	level = l;
}

void Controller::show() const
{
}
