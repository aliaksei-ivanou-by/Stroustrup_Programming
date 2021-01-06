errno = 0;
double s2 = sqrt(-1);
if (errno)
{
	cerr << "Something went wrong\n";
}
if (errno == EDOM)
{
	cerr << "No function SQRT for negative numbers\n";
}
pow(very_large, 2);
if (errno == ERANGE)
{
	cerr << "pow(" << very_large << ", 2) is too big for double\n";
}