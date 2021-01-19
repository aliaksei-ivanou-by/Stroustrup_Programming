#ifndef TASK_25_11_STDAFX_H
#include "Task_25_11_stdafx.h"
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

	std::bitset<32> value;
	value |= ppn.PFN << 12;
	value |= ppn.CCA << 4;
	value |= ppn.nonreachable << 3;
	value |= ppn.dirty << 2;
	value |= ppn.valid << 1;
	value |= ppn.global;
	std::cout << "value = " << value << '\n';
	std::cout << "PPN from value:\n"
		"\tPFN: " << (value >> 12).to_ulong() << '\n' <<
		"\tCCA: " << ((value >> 4) & std::bitset<32>(0x7f)).to_ulong() << '\n' <<
		"\tnonreachable: " << ((value >> 3) & std::bitset<32>(0x1)).to_ulong() << '\n' <<
		"\tdirty: " << ((value >> 2) & std::bitset<32>(0x1)).to_ulong() << '\n' <<
		"\tvalid: " << ((value >> 1) & std::bitset<32>(0x1)).to_ulong() << '\n' <<
		"\tglobal: " << ((value >> 0) & std::bitset<32>(0x1)).to_ulong();
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