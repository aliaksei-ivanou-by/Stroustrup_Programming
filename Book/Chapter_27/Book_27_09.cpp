void* alloc(size_t x);
void f(int n)
{
	int* p = alloc(n * sizeof(int)); /* ok in C */
	/* ... */
}

int* p = (int*)alloc(n * sizeof(int)); /* ok in C and C++ */

void f()
{
	char i = 0;
	char j = 0;
	char* p = &i;
	void* q = p;
	int* pp = q; /* ok in C, error in C++ */
	*pp = -1;
}