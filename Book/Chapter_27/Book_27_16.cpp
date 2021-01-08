#include <stdio.h>
void f(const char* p)
{
	printf("Hello, World!\n");
	printf(p);
}

int printf(const char* format, ...);

void f(double d, char* s, int i, char ch)
{
	printf("double %g string %s int %d char %c\n", d, s, i, ch);
}

char a[] = { 'a', 'b' };
void f2(char* s, int i)
{
	printf("goof %s\n", i);
	printf("goof %d: %s\n", i);
	printf("goof %s\n", a);
}

int fprintf(stdout, "Hello, World!\n");
FILE* ff = fopen("My_file", "w");
fprintf(ff, "Hello, World!\n");