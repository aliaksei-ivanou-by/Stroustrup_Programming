struct Record
{
	string name;
	char addr[24];
	// ...
};

sort(vr.begin(), vr.end(), Cmp_by_name());

sort(vr.begin(), vr.end(), Cmp_by_addr());

struct Cmp_by_name
{
	bool operator()(const Record& a, const Record& b) const
	{
		return a.name < b.name;
	}
};

struct Cmp_by_addr
{
	bool operator()(const Record& a, const Record& b) const
	{
		return strncmp(a.addr, b.addr, 24) < 0;
	}
};