template<typename In, typename T>
T accumulate(In first, In last, T init)
{
	while (first != last)
	{
		init = init + *first;
		++first;
	}
	return init;
}

int a[] = { 1, 2, 3, 4, 5 };
cout << accumulate(a, a + sizeof(a) / sizeof(int), 0);

void f(vector<double& vd, int* p, int n)
{
	double sum = accumulate(vd.begin(), vd.end(), 0.0);
	int sum2 = accumulate(p, p + n, 0);
}

void f(int* p, int n)
{
	int s1 = accumulate(p, p + n, 0);
	long s2 = accumulate(p, p + n, long(0));
	double s3 = accumulate(p, p + n, 0.0);
}

void f(vector<double>& vd, int* p, int n)
{
	double s1 = 0;
	s1 = accumulate(vd.begin(), vd.end(), s1);
	int s2 = accumulate(vs.begin(), vd.end(), s2); // error
	float s3 = 0;
	accumulate(vd.begin(), vd.end(), s3); // error
}