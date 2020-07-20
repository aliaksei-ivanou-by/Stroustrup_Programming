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
	enum Currency
	{
		USD, EUR, BYN
	};
	Money()
		:cents(0), cur(BYN) {}
	Money(long int c)
		:cents(c), cur(BYN) {}
	Money(int d, int c)
		:cents(d*100+c), cur(BYN)
	{
		if (c>=100)
			throw "cents must be between 0 and 99";
	}
	Money(long int c, Currency cur)
		:cents(c), cur(cur) {}
	Money(int d, int c, Currency cur)
		:cents(d*100+c), cur(cur) {}
	int get_dollars() const
	{
		return cents/100;
	}
	int get_cents() const
	{
		return cents%100;
	}
	long int cents;
	Currency cur;
};

double exchange_money(Money::Currency c1, Money::Currency c2)
{
	switch (c1)
	{
	case Money::USD:
		switch (c2)
		{
		case Money::EUR:
			return 1.10;
			break;
		case Money::BYN:
			return 0.47;
			break;
		default:
			 throw "exchange_money: illegal combination of currencies";
		}
	case Money::EUR:
		switch (c2)
		{
		case Money::USD:
			return 0.91;
			break;
		case Money::BYN:
			return 0.43;
			break;
		default:
			throw "exchange_money: illegal combination of currencies";
		}
	case Money::BYN:
		switch (c2)
		{
		case Money::USD:
			return 2.11;
			break;
		case Money::EUR:
			return 2.33;
			break;
		default:
			throw "exchange_money: illegal combination of currencies";
		}
	default:
		throw "exchange_money: illegal combination of currencies";
	}
}

Money operator+(const Money& x, const Money& y)
{
	if (x.cur==y.cur)
		return Money(x.cents+y.cents);
	double z=exchange_money(x.cur, y.cur);
	return Money(x.cents+my_round(z*double(y.cents)), x.cur);
}

Money operator-(const Money& x, const Money& y)
{
	if (x.cur==y.cur)
		return Money(x.cents-y.cents);
	double z=exchange_money(x.cur, y.cur);
	return Money(x.cents-my_round(z*double(y.cents)), x.cur);
}

Money operator-(const Money& x)
{
    return Money(-x.cents, x.cur);
}

Money operator*(int n, const Money& m)
{
    return Money(n*m.cents, m.cur);
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
    return Money(c, m.cur);
}

std::ostream& operator<<(std::ostream& os, const Money::Currency& cur)
{
	switch (cur)
	{
	case Money::USD:
		return os<<"USD";
	case Money::EUR:
        return os<<"EUR";
    case Money::BYN:
        return os<<"BYN";
    }
}

std::ostream& operator<<(std::ostream& os, const Money& input)
{
	os<<input.cur<<input.get_dollars()<<'.';
	if (abs(input.get_cents())<10)
		os<<'0';
	os<<abs(input.get_cents());
    return os;
}

std::istream& operator>>(std::istream& is, Money& m)
{
    int d, c;
    std::string s;
    char ch;
    is>>s>>d>>ch>>c;
    if (!is)
    	return is;
    if (!(s=="USD" || s=="EUR" || s=="BYN") || ch!='.')
    {
        is.clear(std::ios_base::failbit);
        return is;
    }
    Money::Currency cur;
    if (s=="USD")
    	cur=Money::USD;
    else
    	if (s=="EUR")
    		cur=Money::EUR;
    	else
    		if (s=="BYN")
    			cur=Money::BYN;
    		else
    			throw "illegal currency in input";
    if (c<10)
    	m=Money(d, 10*c, cur);
    else
    	m=Money(d, c, cur);
    return is;
}


int main()
{
	Money a=Money(1, 0, Money::BYN);
	Money b=Money(1, 0, Money::EUR);
	Money c=Money(1, 0, Money::USD);
	std::cout<<"a = "<<a<<"\n";
	std::cout<<"b = "<<b<<"\n";
	std::cout<<"c = "<<c<<"\n"<<"\n";
	std::cout<<a<<" + "<<b<<" = "<<a+b<<"\n";
	std::cout <<a<<" + "<<c<<" = "<<a+c<<"\n";
	std::cout<<b<<" + "<<a<<" = "<<b+a<<"\n";
	std::cout<<b<<" + "<<c<<" = "<<b+c<<"\n";
	std::cout<<c<<" + "<<a<<" = "<<c+a<<"\n";
	std::cout<<c<<" + "<<b<<" = "<<c+b<<"\n";
	std::cout<<c<<" - "<<b<<" = "<<c-b<<"\n";
	std::cout<<3<<" * "<<b<<" = "<<3*b<<"\n";
	std::cout<<c<<" / "<<5<<" = "<<c/5<<"\n";
	std::cout<<"Enter amount as in CUR xxx.xx:\n";
	Money d;
	std::cin>>d;
	std::cout<<"d = "<<d<<"\n";
	return 0;
}
