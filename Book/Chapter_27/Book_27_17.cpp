int scanf(const char* format, ...);
int getchar(void);
int getc(FILE* stream);
char* gets(char* s);

char a[12];
gets(a);

void f()
{
	int i;
	char c;
	double d;
	char* s = (char*)malloc(100);
	scanf("%i %c %g %s", &i, &c, &d, s);
}

char buf[20];
scanf("%19s", buf);

while ((x = getchar()) != EOF)
{
	/* ... */
}

string s;
cin >> s;
getline(cin, s);