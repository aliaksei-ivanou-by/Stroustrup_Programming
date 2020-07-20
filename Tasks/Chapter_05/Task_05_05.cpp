#include "iostream"
double ktoc(double);
int main()
{
	double k=0;
	std::cin>>k;
	try
	{
		double c=ktoc(k);
		std::cout<<c<<"\n";
	}
	catch(const char* msg)
	{
		std::cout<<msg;
	}
	return 0;
}
double ktoc(double k)
{
	if (k<0)
		throw "Error, temperature is wrong!\n";
	return k-273.15;
}
