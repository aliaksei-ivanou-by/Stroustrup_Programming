#include "iostream"
double ctok(double);
int main()
{
	double c=0;
	std::cin>>c;
	double k=ctok(c);
	std::cout<<k<<"\n";
	return 0;
}
double ctok(double c)
{
	double k=c+273.15;
	return k;
}
