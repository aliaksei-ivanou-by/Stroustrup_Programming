extern "C" double sqrt(double);

void my_c_plus_plus_fct()
{
	double sq = sqrt(2);
}

extern "C" int call_f(S* p, int i)
{
	return p->f(i);
}

int call_f(S* p, int i);
struct S* make_S(int, const char*);

void my_c_fct(int i)
{
	/* ... */
	struct S* p = make_S(x, "foo");
	int x = call_f(p, i);
	/* ... */
}


class complex
{
	double re, im;
public:
	// ...
};
struct complex
{
	double re, im;
	/* ... */
};