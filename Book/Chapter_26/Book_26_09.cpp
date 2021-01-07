double row_sum(Matrix<double, 2> m, int n);
double row_accum(Matrix<double, 2> m, int n)
{
	double s = 0;
	for (int i = 0; i < n; ++i)
	{
		s += row_sum(m, i);
	}
	return s;
}
vector<double> v;
for (int i = 0; i < m.dim1(); ++i)
{
	v.push_back(row_accum(m, i + 1));
}

for (int i = 0; i < strlen(s); ++i)
{
	// ...
}