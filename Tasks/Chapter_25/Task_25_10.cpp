#ifndef TASK_25_10_STDAFX_H
#include "Task_25_10_stdafx.h"
#endif

int main()
try
{
	PPN ppn;
	ppn.PFN = 0;
	ppn.CCA = 0;
	ppn.nonreachable = 0;
	ppn.dirty = 0;
	ppn.valid = 0;
	ppn.global = 0;
	std::cout << ppn << '\n';

	ppn.PFN = 4095;
	ppn.CCA = 6;
	ppn.nonreachable = 1;
	ppn.dirty = 1;
	ppn.valid = 1;
	ppn.global = 1;
	std::cout << ppn << '\n';

	unsigned int value = 0;
	value |= ppn.PFN << 12;
	value |= ppn.CCA << 4;
	value |= ppn.nonreachable << 3;
	value |= ppn.dirty << 2;
	value |= ppn.valid << 1;
	value |= ppn.global;
	std::cout << "value = " << value << '\n';
	std::cout << "PPN from value:\n"
		"\tPFN: " << (value >> 12) << '\n' <<
		"\tCCA: " << ((value >> 4) & 0x7f) << '\n' <<
		"\tnonreachable: " << ((value >> 3) & 0x1) << '\n' <<
		"\tdirty: " << ((value >> 2) & 0x1) << '\n' <<
		"\tvalid: " << ((value >> 1) & 0x1) << '\n' <<
		"\tglobal: " << ((value >> 0) & 0x1);
}
catch (const std::exception& e)
{
	std::cout << "Exception occured: " << e.what() << '\n';
	return 1;
}
catch (...)
{
	return 2;
}