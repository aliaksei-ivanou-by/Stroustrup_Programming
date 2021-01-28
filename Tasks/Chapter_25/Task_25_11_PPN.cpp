#ifndef TASK_25_11_STDAFX
#include "Task_25_11_stdafx.h"
#include "Task_25_11_PPN.h"
#endif

std::ostream& operator<<(std::ostream& OutputStream, const PPN& ppn)
{
	return OutputStream << "PPN: " << '\n' <<
		"\tPFN: " << ppn.PFN << '\n' <<
		"\tCCA: " << ppn.CCA << '\n' <<
		"\tnonreachable: " << ppn.nonreachable << '\n' <<
		"\tdirty: " << ppn.dirty << '\n' <<
		"\tvalid: " << ppn.valid << '\n' <<
		"\tglobal: " << ppn.global;
}