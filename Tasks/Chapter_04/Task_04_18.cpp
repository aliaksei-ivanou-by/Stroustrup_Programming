#include "iostream"
#include "cmath"
int main()
{
	std::cout<<"Please, enter 'a', 'b', 'c' : ";
	double a, b, c, x1, x2, D;
	std::cin>>a>>b>>c;
	D=b*b-4*a*c;
	std::cout<<"D="<<D<<"\n";
	if (D<0)
	{
		std::cout<<"No solution\n";
	}
	else
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
	return 0;
}
