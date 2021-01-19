#ifndef TASK_25_11_STDAFX_H
#define TASK_25_11_STDAFX_H

#include <iostream>
#include <bitset>

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