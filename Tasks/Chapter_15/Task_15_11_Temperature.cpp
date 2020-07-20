#ifndef TASK_15_11_STDAFX_H
#include "Task_15_11_stdafx.h"
#include "Task_15_11_Temperature.h"
#endif

istream& operator>>(istream& is, Temperature& t)
{
	char ch1 = 0;
	char ch2 = 0;
	char ch3 = 0;
	Temperature tt;
	if (is >> ch1 >> tt.month
		>> ch2 >> tt.t1 >> tt.t2 
		>> ch3)
	{
		if (ch1 != '(' || ch2 != ':' || ch3 != ')')
		{
			is.clear(ios_base::failbit);
			return is;
		}
	}
	else
	{
		return is;
	}
	t = tt;
	return is;
}
