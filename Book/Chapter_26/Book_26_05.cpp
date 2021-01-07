void do_resources(int a, int b, const char* s)
{
	FILE* f = fopen(s, "r");
	int* p = new int[a];
	if (b <= 0)
	{
		throw Bad_arg();
	}
	int* q = new int[b];
	delete[] p;
}

void do_resources2(int a, int b, const char* s)
{
	ifstream is(s);
	vector<int> v1(a);
	if (b <= 0)
	{
		throw Bad_arg();
	}
	vector<int> v2(b);
}

FILE* do_resources3(int a, int* p, const char* s)
{
	FILE* f= fopen(s, "r");
	delete p;
	delete var;
	var = new int[27];
	return f;
}