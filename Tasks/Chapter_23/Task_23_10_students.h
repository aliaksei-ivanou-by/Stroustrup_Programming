#ifndef TASK_23_10_STUDENTS_H
#define TASK_23_10_STUDENTS_H

#ifndef TASK_23_10_STDAFX_H
#include "Task_23_10_stdafx.h"
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

struct students
{
	int boys;
	int girls;
	int total;
};

void dataMerge(
	const std::string& fileNameInput,
	const std::string& fileNameOutput,
	std::map<char, students>& map
);

#endif