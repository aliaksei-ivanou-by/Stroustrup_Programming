#include"iostream"
class Token {
public:
	char kind;
    double value;
    Token(char ch)
        :kind(ch), value(0) { }
    Token(char ch, double val)
    	:kind(ch), value(val) { }
};
Token get_token();
double expression();
double term();
double primary();

int main()
{
	try
	{
		while(std::cin)
		{
			std::cout<<expression()<<"\n";
		}
	}
	catch(const char* msg)
	{
		std::cout<<msg;
	}
	return 0;
}
double expression()
{
	double left=term();
	Token t=get_token();
	while(true)
	{
		switch(t.kind)
		{
		case '+':
			left+=term();
			t=get_token();
			break;
		case '-':
			left-=term();
			t=get_token();
			break;
		default:
			return left;
		}
	}
}
double term()
{
	try
	{
		double left=primary();
		Token t=get_token();
		while(true)
		{
			switch(t.kind)
			{
			case '*':
				left*=primary();
				t=get_token();
				break;
			case '/':
			{
				double d=primary();
				if (d==0)
				{
					throw "Division by zero\n";
				}
				left/=d;
				t=get_token();
				break;
			}
			default:
				return left;
			}
		}
	}
	catch(const char* msg)
	{
		std::cout<<msg;
	}
}
double primary()
{
	try
	{
		Token t=get_token();
		switch(t.kind)
		{
		case '(':
		{
			double d=expression();
			t=get_token();
			if (t.kind!=')')
			{
				throw "')' is required\n";
			}
			return d;
		}
		case '8':
			return t.value;
		default:
			throw "Primary expression required\n";
		}
	}
	catch(const char* msg)
	{
		std::cout<<msg;
	}
}
Token get_token()
{
	try
	{
		char ch;
		std::cin>>ch;
		switch(ch)
		{
		case '(': case ')': case '+': case '-': case '*': case '/':
			return Token(ch);
		case '.':
		case '0': case '1': case '2': case '3': case '4':
		case '5': case '6': case '7': case '8': case '9':
	    	{
	    		std::cin.putback(ch);
	    		double val;
	    		std::cin>>val;
	    		return Token('8', val);
	    	}
		default:
			throw "Bad token\n";
		}
	}
	catch(const char* msg)
	{
		std::cout<<msg;
	}
}
