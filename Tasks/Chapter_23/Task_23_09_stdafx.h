#ifndef TASK_23_09_STDAFX_H
#define TASK_23_09_STDAFX_H
	
#include <iostream>
#include <fstream>
#include <regex>
#include <sstream>

#endif

struct bad_from_string : std::bad_cast
{
	const char* what() const
	{
		return "bad cast from string";
	}
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