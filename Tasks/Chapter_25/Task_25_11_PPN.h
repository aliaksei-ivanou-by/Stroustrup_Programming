#ifndef TASK_25_11_PPN_H
#define TASK_25_11_PPN_H

#ifndef TASK_25_11_STDAFX_H
#include "Task_25_11_stdafx.h"
#endif

struct PPN
{
	unsigned int PFN : 22;
	int : 3;
	unsigned int CCA : 3;
	bool nonreachable : 1;
	bool dirty : 1;
	bool valid : 1;
	bool global : 1;
};

std::ostream& operator<<(std::ostream& OutputStream, const PPN& ppn);

#endif