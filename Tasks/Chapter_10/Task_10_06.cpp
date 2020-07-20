#include "iostream"
#include "fstream"

const char N='N';
const char I='I';
const char V='V';
const char X='X';
const char L='L';
const char C='C';
const char D='D';
const char M='M';

class Roman_int
{
public:
	Roman_int();
	Roman_int(int r_i);
	int as_int() const
	{
		return roman_int;
	}
	void set_val(int v)
	{
		roman_int=v;
	}
private:
	int roman_int;
};

Roman_int::Roman_int()
	:roman_int(0) {}
Roman_int::Roman_int(int r_i)
	:roman_int(r_i) {}

Roman_int operator+(const Roman_int& r_i1, const Roman_int& r_i2)
{
	return Roman_int(r_i1.as_int()+r_i2.as_int());
}
Roman_int operator-(const Roman_int& r_i1, const Roman_int& r_i2)
{
	return Roman_int(r_i1.as_int()-r_i2.as_int());
}
Roman_int operator-(const Roman_int& r_i)
{
	return Roman_int(-r_i.as_int());
}
Roman_int operator*(const Roman_int& r_i1, const Roman_int& r_i2)
{
	return Roman_int(r_i1.as_int()*r_i2.as_int());
}
Roman_int operator/(const Roman_int& r_i1, const Roman_int& r_i2)
try
{
	if (r_i2.as_int()==0)
		throw "division by zero";
	double d=double(r_i1.as_int())/r_i2.as_int();
	int res=int(d);
	if (res!=d)
		throw "division leads to non-integer result\n";
	return Roman_int(res);
}
catch(const char* msg)
{
	std::cout<<msg;
}
Roman_int operator%(const Roman_int& r_i1, const Roman_int& r_i2)
{
	return Roman_int(r_i1.as_int()%r_i2.as_int());
}
bool operator==(const Roman_int& r_i1, const Roman_int& r_i2)
{
	return r_i1.as_int()==r_i2.as_int();
}
bool operator!=(const Roman_int& r_i1, const Roman_int& r_i2)
{
	return !(r_i1==r_i2);
}
bool operator<(const Roman_int& r_i1, const Roman_int& r_i2)
{
	return r_i1.as_int()<r_i2.as_int();
}
bool operator>(const Roman_int& r_i1, const Roman_int& r_i2)
{
	return r_i2<r_i1;
}
bool operator<=(const Roman_int& r_i1, const Roman_int& r_i2)
{
	return !(r_i2<r_i1);
}
bool operator>=(const Roman_int& r_i1, const Roman_int& r_i2)
{
	return !(r_i1<r_i2);
}
bool is_valid_char(char ch)
{
	return ch==N || ch==I || ch==V || ch==X || ch==L || ch==C || ch==D || ch==M;
}
int get_value(char ch)
try
{
	switch (ch)
	{
	case N:
		return 0;
	case I:
	    return 1;
	case V:
	    return 5;
	case X:
	    return 10;
	case L:
	    return 50;
	case C:
	    return 100;
	case D:
	    return 500;
	case M:
	    return 1000;
	default:
	    throw "illegal letter used\n";
	}
}
catch(const char* msg)
{
	std::cout<<msg;
}
bool counter_illegal(int counter, char ch)
try
{
	switch (ch)
	{
	case N:
	case V:
	case L:
	case D:
		return counter>1;
	case I:
	case X:
	case C:
	case M:
		return counter>3;
	default:
		throw "counter_illegal: invalid character\n";
	}
}
catch(const char* msg)
{
	std::cout<<msg;
}
int roman_int_to_int(const std::string& s)
try
{
	 if (s.size()==0)
		 throw "roman_to_int: empty string\n";
	 if (s.size()==1)
		 return get_value(s[0]);
	 int counter=1;
	 int val=get_value(s[s.size()-1]);
	 int min_val=val;
	 for (int i=s.size()-2; i>=0; --i)
	 {
		 if (s[i]==s[i+1])
		 {
			 ++counter;
			 if (counter_illegal(counter,s[i]))
				 throw "illegal repetition of letter\n";
		 }
		 else counter=1;
		 if (get_value(s[i])<get_value(s[i+1]))
		 {
			 if ((s[i]==I || s[i]==X || s[i]==C) && get_value(s[i+1])<=10*get_value(s[i]))
				 val-=get_value(s[i]);
			 else
				 throw "illegal use value\n";
		 }
		 else
		 {
			 val+=get_value(s[i]);
			 min_val=get_value(s[i]);
		 }
	 }
	 return val;
}
catch(const char* msg)
{
	std::cout<<msg;
}
std::ostream& operator<<(std::ostream& os, const Roman_int& r_i)
{
	int val=r_i.as_int();
	if (val==0)
		return os<<N;
	if (val<0)
	{
		os <<'-';
		val=-val;
	}
	while (val>=1000)
	{
		os<<M;
		val-=1000;
	}
	if (val>=900)
	{
		os<<C<<M;
		val-=900;
	}
	else
		if (val>=500)
		{
			os<<D;
			val-=500;
		}
		else
			if (val>=400)
			{
				os<<C<<D;
				val-=400;
			}
	while (val>=100)
	{
		os<<C;
		val-=100;
	}
	if (val>=90)
	{
		os<<X<<C;
		val-=90;
	}
	else
		if (val>=50)
		{
			os<<L;
			val-=50;
		}
		else
			if (val>=40)
			{
				os<<X<<L;
				val-=40;
			}
	while (val>=10)
	{
		os<<X;
		val-=10;
	}
	if (val==9)
	{
		os<<I<<X;
		val-=9;
	}
	else
		if (val>=5)
		{
			os<<V;
			val-=5;
		}
		else
			if (val==4)
			{
				os<<I<<V;
				val-=4;
			}
	while (val>=1)
	{
		os<<I;
		--val;
	}
	return os;
}
std::istream& operator>>(std::istream& is, Roman_int& r_i)
{
	is.exceptions(is.exceptions()|std::ios_base::badbit);
	std::string s;
	char ch;
	while (is.get(ch))
	{
		if (is_valid_char(ch))
			s+=ch;
		else
		{
			is.putback(ch);
			break;
		}
	}
	int val=roman_int_to_int(s);
	r_i.set_val(val);
	return is;
}
int main()
try
{
	std::cout<<Roman_int(0)<<" equals "<<Roman_int(0).as_int()<<"\n";
	std::cout<<Roman_int(1)<<" equals "<<Roman_int(1).as_int()<<"\n";
	std::cout<<Roman_int(4)<<" equals "<<Roman_int(4).as_int()<<"\n";
	std::cout<<Roman_int(5)<<" equals "<<Roman_int(5).as_int()<<"\n";
	std::cout<<Roman_int(8)<<" equals "<<Roman_int(8).as_int()<<"\n";
	std::cout<<Roman_int(9)<<" equals "<<Roman_int(9).as_int()<<"\n";
	std::cout<<Roman_int(10)<<" equals "<<Roman_int(10).as_int()<<"\n";
	std::cout<<Roman_int(48)<<" equals "<<Roman_int(48).as_int()<<"\n";
	std::cout<<Roman_int(81)<<" equals "<<Roman_int(81).as_int()<<"\n";
	std::cout<<Roman_int(99)<<" equals "<<Roman_int(99).as_int()<<"\n";
	std::cout<<Roman_int(105)<<" equals "<<Roman_int(105).as_int()<<"\n";
	std::cout<<Roman_int(2014)<<" equals "<<Roman_int(2014).as_int()<<"\n";
	std::cout<<Roman_int(-2014)<<" equals "<<Roman_int(-2014).as_int()<<"\n";
	std::cout<<Roman_int(1499)<<" equals "<<Roman_int(1499).as_int()<<"\n\n";
	std::cout<<Roman_int(1)<<" + "<<Roman_int(3)<< " = "<<Roman_int(1)+Roman_int(3)<<"\n";
	std::cout<<Roman_int(15)<<" * "<<Roman_int(37)<< " = "<<Roman_int(15)*Roman_int(37)<<"\n";
	std::cout<<Roman_int(105)<<" - "<<Roman_int(207)<< " = "<<Roman_int(105)-Roman_int(207)<<"\n";
	std::cout<<-Roman_int(7)<<" * "<<Roman_int(5)<< " = "<<-Roman_int(7)*Roman_int(5)<<"\n";
	std::cout<<Roman_int(15)<<" / "<<Roman_int(5)<<" = "<<Roman_int(15)/Roman_int(5)<<"\n";
}
catch(const char* msg)
{
	std::cout<<msg;
}
