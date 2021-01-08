struct pair { int x, y; };
pair p1; // error
struct pair p2; // ok
int pair = 7; // ok
struct pair p3; // ok
pair = 8; // ok

typedef struct { int x, y; } pair;
pair p1 = { 1, 2 };

struct S
{
	struct T
	{
		/* ... */
	};
	/* ... */
};
struct T x;
S::T x;