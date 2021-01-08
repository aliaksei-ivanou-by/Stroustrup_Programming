const int max = 30
const int x; /* ok in C, error in C++ */
void f(int v)
{
	int a1[max]; /* error in C, ok in C++ */
	int a2[x];
	switch (v)
	{
		case 1:
		{
			/* ... */
			break;
		}
		case max: /* error in C, ok in C++ */
		{
			/* ... */
			break;
		}
	}
}

#define MAX 30
void f(int v)
{
	int a1[MAX];
	switch (v)
	{
		case 1:
		{
			/* ... */
			break;
		}
		case MAX:
		{
			/* ... */
			break;
		}
	}
}