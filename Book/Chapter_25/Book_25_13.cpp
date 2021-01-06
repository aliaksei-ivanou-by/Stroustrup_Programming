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

void part_of_VM_system(PPN * p)
{
	// ...
	if (p->dirty)
	{
		p->dirty = 0;
	}
	// ...
}

unsigned int x = pn.CCA;

unsigned int y = (pni >> 4) & 0x7;