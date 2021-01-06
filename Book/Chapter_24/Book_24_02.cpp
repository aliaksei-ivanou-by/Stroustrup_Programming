short int y = 40000;
int i = 1000000;
cout << y << " " << i * i << '\n';

cout << "Sizes : " << sizeof(int) << ' ' << 
						sizeof(float) << '\n';
int x = 2100000009;
float f = x;
coust << x << ' ' << f << '\n';
cout << setprecision(15) << x << ' ' << f << '\n';

float f = 2.8;
int x = f;
cout << x << ' ' << f << '\n';

void f(int i, double fpd)
{
	char c = i;
	short s = i;
	i = i + i;
	long lg = i * i;
	float fps = fpd;
	i = fpd;
	fps = i;
}
void g()
{
	char ch = 0;
	for (int i = 0; i < 500; ++i)
	{
		cout << int(ch++) << '\t';
	}
}