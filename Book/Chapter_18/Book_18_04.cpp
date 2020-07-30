class vector
{
	int sz;
	double* elem;
public:
	vector(int s)
		: sz{ s },
		elem{ new double([sz]) }
	{
		// ...
	}
	vector(const vector& arg)
		: sz{ arg.sz },
		elem{ new double[arg.sz] }
	{
		copy(arg, arg + sz, elem);	
	}
	~vector()
	{
		delete[] elem;
	}
};