#ifndef TASK_24_01_STDAFX_H
#define TASK_24_01_STDAFX_H

#include <iostream>
#include "Matrix.h"
#include "MatrixIO.h"

#endif

inline void tripleRef(int& n) // Modifies input parameter
{
	n *= 3;
}

inline int tripleInt(int n) // Doesn't modify input parameter
{
	return n * 3;
}

inline int tripleIntRef(int& n) // Modifies input parameter
{
	return n *= 3;
}