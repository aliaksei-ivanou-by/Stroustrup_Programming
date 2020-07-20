clacc vector
{
	int sz;
	double* elem;
public:
	vector(int s)
	: sz(s), 
	  elem(new double[s])
	{
		for (int i = 0; i < s; ++i)
		{
			elem[i] = 0;
		}
	}
	int size() const
	{
		return sz;
	}
	~vector()
	{
		delete[] elem;
	}
};