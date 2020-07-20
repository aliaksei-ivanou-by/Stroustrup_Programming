Shape* fct()
{
	Text tt{Point(200, 200), "Annemarie"};
	Shape* p = new Text{Point(100, 100), "Nicolas"};
	return p;
}

void f()
{
	Shape* q = fct();
	delete q;
}