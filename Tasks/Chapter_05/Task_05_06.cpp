#include "iostream"
double ctof(double);
double ftoc(double);
int main()
{
	double c=0;
	std::cout<<"Celsius to Fahrenheit\n";
	std::cin>>c;
	try
	{
		double f=ctof(c);
		std::cout<<f<<"\n";
	}
	catch(const char* msg)
	{
		std::cout<<msg;
	}

	double f=0;
	std::cout<<"Fahrenheit to Celsius\n";
	std::cin>>f;
	try
	{
		double c=ftoc(f);
		std::cout<<c<<"\n";
	}
	catch(const char* msg)
	{
		std::cout<<msg;
	}
	return 0;
}
double ctof(double c)
{
	if (c<-273.15)
		throw "Error, temperature is wrong!\n";
	return (c*9.0/5)+32;
}
double ftoc(double f)
{
	if (f<-459.4)
		throw "Error, temperature is wrong!\n";
	return (f-32)*(5.0/9);
}
