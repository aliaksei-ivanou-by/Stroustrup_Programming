#ifndef TASK_23_09_FROM_STRING_H
#define TASK_23_09_FROM_STRING_H

#ifndef TASK_23_09_STDAFX_H
#include "Task_23_09_stdafx.h"
#endif

struct bad_from_string : std::bad_cast
{
	const char* what() const;
};

template<class T>
T from_string(const std::string& s)
{
	std::istringstream is(s);
	T t;
	if (!(is >> t))
	{
		throw bad_from_string();
	}
	return t;
}

#endif