struct Record
{
	string name;
	char addr[24];
	// ...
};

sort(vr.begin(), vr.end(), 
	[] (const Record& a, const Record& b)
	{ return a.name < b.name; }
);

sort(vr.begin(), vr.end(), 
	[] (const Record& a, const Record& b)
	{ return strncmp(a.addr, b.addr, 24) < 0; }
);