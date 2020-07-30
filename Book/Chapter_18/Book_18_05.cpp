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
	vector& operator=(const vector& a)
	{
		double* p = new double[a.sz];
		copy(a.elem, a.elem + a.sz, p);
		delete[] elem;
		elem = p;
		sz = a.sz;
		return *this;
	}
	~vector()
	{
		delete[] elem;
	}
};