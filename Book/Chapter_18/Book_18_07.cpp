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
	vector(vector&& a)
		: sz{ a.sz },
		elem{ a.elem }
	{
		a.sz = 0;
		a.elem = nullptr;
	}
	vector& operator=(vector&& a)
	{
		delete[] elem;
		elem = a.elem;
		sz = a.sz;
		a.elem = nullptr;
		a.sz = 0;
		return *this;
	}
	~vector()
	{
		delete[] elem;
	}
};

vector* fill2(istream& is)
{
	vector* res = new vector;
	for (double x; is >> x; )
	{
		res->push_back(x);
	}
	return res;
}

void use2()
{
	vector* vec = fill(cin);
	// ...
	delete vec;
}