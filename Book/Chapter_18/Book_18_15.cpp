class vector
{
	int sz;
	double* elem;
public:
	// ...
	double& operator[](int n)
	{
		return elem[n];
	}
	double operator[](int n) const
	{
		return elem[n];
	}
};

int main()
{
	vector v(10);
	for (int i = 0; i < v.size(); ++i)
	{
		v[i] = i;
		std::cout << v[i] << '\n';
	}
}