#ifndef BOOK_15_03_SCALE_H
#define BOOK_15_03_SCALE_H

#ifndef BOOK_15_03_STDAFX_H
#include "Book_15_03_stdafx.h"
#endif

class Scale
{
public:
	Scale(int b, int vb, double s);
	int operator()(int v) const;
private:
	int cbase;
	int vbase;
	double scale;
};

#endif