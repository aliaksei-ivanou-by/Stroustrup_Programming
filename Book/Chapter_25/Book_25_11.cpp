for (vector<int>::size_type i = 0; i < v.sive(); ++i)
{
	cout << v[i] << '\n';
}

for (auto p = v.begin(), p != v.end(); ++p)
{
	cout << *p << '\n';
}

for (int x : v)
{
	cout << x << '\n';
}

unsigned int ui = -1;
int si = ui;
int si2 = ui + 2;
unsigned ui2 = ui + 2;

Int i = 0;
while (++i)
{
	print(i);
}

int si = 257;
char c = si;
unsigned char uc = si;
signed char sc = si;
print(si); // 257
print(c); // 1
print(uc); // 1
print(sc); // 1
coust << '\n';
si = 129;
c = si;
uc = si;
sc = si;
print(si); // 129
print(c); // -127
print(uc); // 129
print(sc); // -127

template<typename T>
void print(T i)
{
	cout << i << '\t';
}
void print(char i)
{
	cout << int(i) << '\t';
}
void print(signed char i)
{
	cout << int(i) << '\t';
}
void print(unsigned char i)
{
	cout << int(i) << '\t';
}