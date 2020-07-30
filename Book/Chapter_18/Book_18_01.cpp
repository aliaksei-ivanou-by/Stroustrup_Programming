class vector
{
	int sz;
	double* elem;
public:
	vector(int s)
	: sz{ s },
	elem{ new double([s]) }
	{
		// ...
	}
	~vector()
	{
		delete[] elem;
	}
};