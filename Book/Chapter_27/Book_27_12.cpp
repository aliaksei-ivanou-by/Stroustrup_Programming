void* malloc(size_t sz);
void free(void* p);
void* calloc(size_t n, size_t sz);
void* realloc(void* p, size_t sz);

struct Pair
{
	const char* p;
	int val;
};
struct Pair p2 = { "apple", 78};
struct Pair* pp = (struct Pair*)malloc(sizeof(Pair));
pp->p = "pear";
pp->val = 42;
*pp = { "pear", 42 }; /* error in C and C++98 */
Pair* pp = new Pair("pear", 42); // ok in C++
int* p = malloc(sizeof(int)*n); /* C */
p = malloc(sizeof(char)*m); /* may be error */

int* p = new int[200];
// ...
free(p); // error

X* q = (X*)malloc(n * sizeof(X));
// ...
delete q; // error

int max = 1000;
int count = 0;
int c;
char* c = (char*)malloc(max);
while ((c = getchar() != EOF))
{
	if (count == max - 1)
	{
		max += max;
		p = (char*)realloc(p, max);
		if (p == 0)
		{
			quit();
		}
	}
	p[count++] = c;
}