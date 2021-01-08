double square(double d)
{
	return d * d;
}

void ff()
{
	double x = square(2); // ok
	double y = square(); // miss argument
	double y = square("Hello"); // error
	double y - square(2, 3); // error
}

void f()
{
	// ...
}

void g()
{
	f(2); 
}

void f(void);

int old_style(p, b, x) char* p; char b;
{
	/* ... */
}

old_style();
old_style("hello", 'a', 17);
old_style(12, 13, 14);