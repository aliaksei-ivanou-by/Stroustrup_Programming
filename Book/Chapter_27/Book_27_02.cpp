int main()
{
	f(2);
}

/* other_file.c: */
int f(char* p)
{
	int r = 0;
	while (*p++)
	{
		r++;
	}
	return r;
}

int g(double);
int h();

void my_fct()
{
	g(); // error
	g("asdf"); // error
	g(2); // ok
	g(2, 3); // error
	
	h(); // ok
	h("asdf"); // ok
	h(2); // ok
	h(2, 3); // ok
}