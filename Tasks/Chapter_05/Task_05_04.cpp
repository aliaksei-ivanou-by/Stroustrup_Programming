#include "iostream"
double ctok(double);
int main()
{
	double c=0;
	std::cin>>c;
	try
	{
		double k=ctok(c);
		std::cout<<k<<"\n";
	}
	catch(const char* msg)
	{
		std::cout<<msg;
	}
	return 0;
}
double ctok(double c)
{
	if (c<-273.15)
		throw "Error, temperature is wrong!\n";
	return c+273.15;
}
