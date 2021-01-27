#ifndef TASK_23_09_STDAFX
#include "Task_23_09_stdafx.h"
#include "Task_23_09_from_string.h"
#endif

const char* bad_from_string::what() const
{
	return "bad cast from string";
}
