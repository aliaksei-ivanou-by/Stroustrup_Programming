#include <iostream>

class vector
{
	int sz;
	double* elem;
public:
	vector(int s)
		: sz{ s },
		elem{ new double[s] }
	{
		for (int i = 0; i < sz; ++i)
		{
			elem[i] = 0.0;
		}
	}
	vector(std::initializer_list<double> lst)
		: sz{ static_cast<int>(lst.size()) },
		elem{ new double[sz] }
	{
		std::copy(lst.begin(), lst.end(), elem);
	}
	~vector()
	{
		delete[] elem;
	}
};

int main(int argc, char** argv)
try
{
	vector v1 = { 1, 2, 3 }; // 1.0, 2.0, 3.0
	vector v2(3); // 0.0, 0.0, 0.0

	vector v3{ 3 }; // 3.0
	vector v4(3); // 0.0, 0.0, 0.0

	vector v5 = { 1, 2, 3 }; // 1.0, 2.0, 3.0
	vector v6{ 1, 2, 3 }; // 1.0, 2.0, 3.0
}
catch (const std::exception& e)
{
	std::cout << "Exception occured: " << e.what() << '\n';
	return 1;
}
catch (...)
{
	return 2;
}