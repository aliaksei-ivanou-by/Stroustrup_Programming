#ifndef TASK_15_01_STDAFX_H
#define TASK_15_01_STDAFX_H

#include <iostream>
#include <string>
#include "std_lib_facilities.h"

long long fac(int n)
{
	return n > 1 ? n * fac(n - 1) : 1;
}

#endif