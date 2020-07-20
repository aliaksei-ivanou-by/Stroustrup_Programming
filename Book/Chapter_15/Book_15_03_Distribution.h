#ifndef BOOK_15_03_DISTRIBUTION_H
#define BOOK_15_03_DISTRIBUTION_H

#ifndef BOOK_15_03_STDAFX_H
#include "Book_15_03_stdafx.h"
#endif

struct Distribution
{
public:
	int year;
	int young;
	int middle;
	int old;
};

istream& operator>>(istream& is, Distribution& d);

#endif