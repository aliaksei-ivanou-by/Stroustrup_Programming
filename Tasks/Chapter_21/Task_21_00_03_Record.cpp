#include <iostream>
#include <vector>
#include <numeric>

class Record
{
public:
	double unit_price;
	int units;
	Record(double up, int u):
		unit_price{ up },
		units{ u }
	{}
};

double price(const double v, const Record& r)
{
	return v + r.unit_price * r.units;
}

void f(const std::vector<Record>& vr)
{
	double total = accumulate(vr.begin(), vr.end(), 0.0, price);
	std::cout << "Total number is " << total << '\n';
}

int main()
try
{
	std::vector<Record> myVector;
	myVector.push_back(Record{ 1.1, 1 });
	myVector.push_back(Record{ 2.2, 2 });
	myVector.push_back(Record{ 3.3, 3 });
	myVector.push_back(Record{ 4.4, 4 });
	f(myVector);
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