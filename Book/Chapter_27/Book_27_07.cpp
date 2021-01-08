for (int i = 0; i < max; ++i)
{
	x[i] = y[i];
}
while (struct S* p = next(q))
{
	/* ... */
}
void f(int i)
{
	if (i < 0 || max <= i)
	{
		error("Range error");
	}
	{
		int a[max];
		/* ... */
	}
}

int i;
for (i = 0; i < max; ++i)
{
	x[i] = y[i];
}
struct S* p;
while (p = next(q))
{
	/* ... */
}
void f(int i)
{
	if (i < 0 || max <= i)
	{
		error("Range error");
	}
	{
		int a[max];
		/* ... */
	}
}

/* x.c: */
int x = 0;
/* y.c: */
extern int x;

/* x.h: */
extern int x;
/* x.c: */
#include "x.h"
int x = 0;
/* y.c: */
#include "x.h"