#include "iostream"
#include "cmath"
int main()
{
	std::cout<<"Please, enter 'a', 'b', 'c' : ";
	double a, b, c, x1, x2, D;
	std::cin>>a>>b>>c;
	try
	{
		D=b*b-4*a*c;
		if (D<0)
		{
			throw "D<0. No solution\n";
		}
		if (D==0)
		{
			x1=(-1)*(b/(2*a));
			x2=x1;
			std::cout<<"x1="<<x1<<", x2="<<x2<<"\n";
		}
		else
		{
			x1=(-b+sqrt(b*b-4*a*c))/(2*a);
			x2=(-b-sqrt(b*b-4*a*c))/(2*a);
			std::cout<<"x1="<<x1<<", x2="<<x2<<"\n";
		}
	}
	catch(const char* msg)
	{
		std::cout<<msg;
	}
	return 0;
}
