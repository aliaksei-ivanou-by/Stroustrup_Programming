#include "iostream"

long int my_round(double input)
{
	long int output;
	if (input>0.0)
		output=input+0.5;
	else
		output=input-0.5;
	return output;
}

class Money
{
public:
	Money()
		:cents(0) {}
	Money(long int c)
		:cents(c) {}
	Money(int d, int c)
		:cents(d*100+c)
	{
		if (c>=100)
			throw "cents must be between 0 and 99";
	}
	int get_dollars() const
	{
		return cents/100;
	}
	int get_cents() const
	{
		return cents%100;
	}
	long int cents;
};

Money operator+(const Money& x, const Money& y)
{
	return Money(x.cents+y.cents);
}

Money operator-(const Money& x, const Money& y)
{
	return Money(x.cents-y.cents);
}

Money operator*(int n, const Money& m)
{
    return Money(n*m.cents);
}

Money operator*(const Money& m, int n)
{
    return n*m;
}

Money operator/(const Money& m, int n)
{
    if (n==0)
    	throw "division by zero";
    double d=double(m.cents)/n;
    long int c=my_round(d);
    return Money(c);
}

std::ostream& operator<<(std::ostream& os, const Money& input)
{
	os<<"$"<<input.get_dollars()<<'.';
	if (abs(input.get_cents())<10)
		os<<'0';
	os<<abs(input.get_cents());
    return os;
}

int main()
{
	Money x1;
	Money x2(405);
	Money x3(2, 9);

	std::cout<<"x1: "<<x1<<"\n";
	std::cout<<"x2(405): "<<x2<<"\n";
	std::cout<<"x3(55, 9): "<<x3<<"\n";

	std::cout<<x2<<" + "<<x3<<" = "<<x2+x3<<"\n";
	std::cout<<x2<<" - "<<x3<<" = "<<x2-x3<<"\n";
	std::cout<<"5 * "<<x2<<" = "<<5*x2<<"\n";
	std::cout<<x2<<" * 5 = "<<x2*5<<"\n";
	std::cout<<x3<<" - "<<x2<<" = "<<x3-x2<<"\n";
	std::cout<<Money(1,0)<<" / 7 = "<<Money(1,0)/7<<"\n";
	std::cout<<Money(0,9)<<" / 6 = "<<Money(0,9)/6<<"\n\n";
	return 0;
}
