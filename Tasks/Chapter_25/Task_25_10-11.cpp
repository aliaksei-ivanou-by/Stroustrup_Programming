#include <iostream>
#include <bitset>

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

	unsigned int valueInt = 0;
	valueInt |= ppn.PFN << 12;
	valueInt |= ppn.CCA << 4;
	valueInt |= ppn.nonreachable << 3;
	valueInt |= ppn.dirty << 2;
	valueInt |= ppn.valid << 1;
	valueInt |= ppn.global;
	std::cout << "value = " << valueInt << '\n';
	std::cout << "PPN from valueInt:\n"
		"\tPFN: " << (valueInt >> 12) << '\n' <<
		"\tCCA: " << ((valueInt >> 4) & 0x7f) << '\n' <<
		"\tnonreachable: " << ((valueInt >> 3) & 0x1) << '\n' <<
		"\tdirty: " << ((valueInt >> 2) & 0x1) << '\n' <<
		"\tvalid: " << ((valueInt >> 1) & 0x1) << '\n' <<
		"\tglobal: " << ((valueInt >> 0) & 0x1);

	std::bitset<32> valueBitset;
	valueBitset |= ppn.PFN << 12;
	valueBitset |= ppn.CCA << 4;
	valueBitset |= ppn.nonreachable << 3;
	valueBitset |= ppn.dirty << 2;
	valueBitset |= ppn.valid << 1;
	valueBitset |= ppn.global;
	std::cout << "value = " << valueBitset << '\n';
	std::cout << "PPN from valueBitset:\n"
		"\tPFN: " << (valueBitset >> 12).to_ulong() << '\n' <<
		"\tCCA: " << ((valueBitset >> 4) & std::bitset<32>(0x7f)).to_ulong() << '\n' <<
		"\tnonreachable: " << ((valueBitset >> 3) & std::bitset<32>(0x1)).to_ulong() << '\n' <<
		"\tdirty: " << ((valueBitset >> 2) & std::bitset<32>(0x1)).to_ulong() << '\n' <<
		"\tvalid: " << ((valueBitset >> 1) & std::bitset<32>(0x1)).to_ulong() << '\n' <<
		"\tglobal: " << ((valueBitset >> 0) & std::bitset<32>(0x1)).to_ulong();
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