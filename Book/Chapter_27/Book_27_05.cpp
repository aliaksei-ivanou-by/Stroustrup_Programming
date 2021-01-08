struct Shape1
{
	enum Kind
	{
		circle,
		rectangle
	}
	kind;
	/* ... */
};
void draw(struct Shape1* p)
{
	switch (p->kind)
	{
		case circle:
		{
			/* draw circle */
			break;
		}
		case rectangle:
		{
			/* draw rectangle */
			break;
		}
	}
}
int f(struct Shape1* pp)
{
	draw(pp);
	/* ... */
}


typedef void (*Pfct0)(struct Shape2*);
typedef void (*Pfct1int)(struct Shape2*, int);
struct Shape2
{
	Pfct0 draw;
	Pfct1int rotate;
	/* ... */
};
void draw(struct Shape2* p)
{
	(p->draw)(p);
}
void rotate(struct Shape2* p, int d)
{
	(p->rotate)(p, d);
}
int f(struct Shape2* pp)
{
	draw(pp);
	/* ... */
}