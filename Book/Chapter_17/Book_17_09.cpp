vector* f(int s)
{
	vector* p = new vector(s);
	return p;
}

void ff()
{
	vector* q = f(4);
	delete q;
}