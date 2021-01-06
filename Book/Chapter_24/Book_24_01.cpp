float x = 1.0 / 333;
float sum = 0;
for (int i = 0; i < 333; ++i)
{
	sum += x;
}
cout << setprecision(15) << sum << '\n';