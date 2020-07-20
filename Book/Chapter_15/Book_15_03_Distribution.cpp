#ifndef BOOK_15_03_STDAFX_H
#include "Book_15_03_stdafx.h"
#include "Book_15_03_Distribution.h"
#endif

istream& operator>>(istream& is, Distribution& d)
{
	char ch1 = 0;
	char ch2 = 0;
	char ch3 = 0;
	Distribution dd;
	if (is >> ch1 >> dd.year 
		>> ch2 >> dd.young >> dd.middle >> dd.old 
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
	d = dd;
	return is;
}
