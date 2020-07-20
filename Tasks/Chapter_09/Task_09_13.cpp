#include "iostream"

int gcd(int a, int b)
{
	while (b!=0)
	{
		int t=b;
		b=a%b;
		a=t;
	}
	return a;
}

class Rational
{
public:
	Rational()
		:numer(0), denom(1) {}
	Rational(int n)
		:numer(n), denom(1) {}
	Rational(int n, int d)
		:numer(n), denom(d)
	{
		normal();
	}
	int get_numer() const
	{
		return numer;
	}
	int get_denom() const
	{
		return denom;
	}
	double conv2double() const
	{
		return double(numer)/denom;
	}
	void normal()
	{
		if (denom==0)
			throw "denominator is zero";
		if (denom<0)
		{
			denom=-denom;
			numer=-numer;
		}
		int n=gcd(numer, denom);
		if (n>1)
		{
			numer/=n;
			denom/=n;
		}
	}
private:
	 int numer;
	 int denom;
};

Rational operator+(const Rational& x, const Rational& y);
Rational operator-(const Rational& x, const Rational& y);
Rational operator*(const Rational& x, const Rational& y);
Rational operator/(const Rational& x, const Rational& y);
bool operator==(const Rational& x, const Rational& y);
bool operator!=(const Rational& x, const Rational& y);
std::ostream& operator<<(std::ostream& os, const Rational& x);

Rational operator+(const Rational& x, const Rational& y)
{
	Rational z(x.get_numer()*y.get_denom()+x.get_denom()*y.get_numer(),
			x.get_denom()*y.get_denom());
	z.normal();
	return z;
}
Rational operator-(const Rational& x, const Rational& y)
{
	Rational z(x.get_numer()*y.get_denom()-x.get_denom()*y.get_numer(),
			x.get_denom()*y.get_denom());
	z.normal();
	return z;
}
Rational operator*(const Rational& x, const Rational& y)
{
	Rational z(x.get_numer()*y.get_numer(), x.get_denom()*y.get_denom());
	z.normal();
	return z;
}
Rational operator/(const Rational& x, const Rational& y)
{
	Rational z(x.get_numer()*y.get_denom(), x.get_denom()*y.get_numer());
	z.normal();
	return z;
}
bool operator==(const Rational& x, const Rational& y)
{
	return x.get_numer()*y.get_denom()==x.get_denom()*y.get_numer();
}
bool operator!=(const Rational& x, const Rational& y)
{
	return !(x==y);
}
std::ostream& operator<<(std::ostream& os, const Rational& x)
{
	return std::cout<<'('<<x.get_numer()<<'/'<<x.get_denom()<<')';
}

int main()
{
	Rational x1;
	Rational x2(7);
	Rational x3(3, 5);
	std::cout<<"x1: "<<x1<<"\n"
			<<"x2: "<<x2<<"\n"
			<<"x3: "<<x3<<"\n";

	std::cout<<"2/3 + 4/7 = "<<Rational(2, 3)+Rational(4, 7)<<
			" = "<<(Rational(2, 3)+Rational(4, 7)).conv2double()<<"\n";
	std::cout<<"8/9 - 2/7 = "<<Rational(8, 9)-Rational(2, 7)<<
			" = "<<(Rational(8, 9)-Rational(2, 7)).conv2double()<<"\n";
	std::cout<<"8/9 * 2/7 = "<<Rational(8, 9)*Rational(2, 7)<<
			" = "<< (Rational(8, 9)*Rational(2, 7)).conv2double()<<"\n";
	std::cout<<"(8/9) / (1/3) = "<<Rational(8, 9)/Rational(1, 3)<<
			" = "<<(Rational(8, 9)/Rational(1, 3)).conv2double()<<"\n";

	if (x1==Rational(0, 1))
		std::cout<<"x1 == 0/1"<<"\n";
	if (Rational(1, 2)==Rational(2, 4))
		std::cout<<"1/2 == 2/4" <<"\n";
	if (x2!=x2)
		std::cout<<"x2 != x2"<<"\n";
	std::cout<<x3<<" = "<<x3.conv2double()<<"\n";
	return 0;
}
