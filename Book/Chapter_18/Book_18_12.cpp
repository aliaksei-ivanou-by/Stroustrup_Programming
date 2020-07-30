class vector
{
	int sz;
	double* elem;
public:
	// ...
	double operator[](int n)
	{
		return elem[n];
	}
};

int main()
{
	vector v(10);
	int x = v[2]; // OK
	v[3] = x; // Error
}