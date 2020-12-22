struct Record
{
	double unit_price;
	int units;
	// ...
};

double price(double v, const Record& r)
{
	return v + r.unit_price * r.units;
}

void f(const vector<Record>& vr)
{
	double total = accumulate(vr.begin(), vr.end(), 0.0, price);
	// ...
}