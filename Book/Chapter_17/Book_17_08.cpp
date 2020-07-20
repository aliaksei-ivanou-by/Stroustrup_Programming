class vector
{
	int sz;
	double* elem;
public:
	vector(int s)
	: sz{ s },
	  elem{ new double[s] }
	{
		// ...
	}
	~vector()
	{
		delete[] elem;
	}
	int size() const
	{
		return sz;
	}
	double get(int n) const
	{
		return elem[n];
	}
	void set(int n, double v)
	{
		elem[n] = v;
	}
};
		