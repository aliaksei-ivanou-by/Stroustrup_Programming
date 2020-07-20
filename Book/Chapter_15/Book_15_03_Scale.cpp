#ifndef BOOK_15_03_STDAFX_H
#include "Book_15_03_stdafx.h"
#include "Book_15_03_Scale.h"
#endif

Scale::Scale(int b, int vb, double s)
	: cbase{ b }, vbase{ vb }, scale{ s }
{
}

int Scale::operator()(int v) const
{
	return cbase + (v - vbase) * scale;
}
