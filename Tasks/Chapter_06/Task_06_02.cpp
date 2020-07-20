#include "iostream"

class Token
{
public:
    char kind;
    double value;
    Token(char ch)
        :kind(ch), value(0) {}
    Token(char ch, double val)
        :kind(ch), value(val) {}
};

class Token_stream
{
public:
    Token_stream();
    Token get();
    void putback(Token t);
private:
    bool full;
    Token buffer;
};

Token_stream::Token_stream()
:full(false), buffer(0)
{
}

void Token_stream::putback(Token t)
{
	try
	{
		if (full) throw "putback() into a full buffer";
    buffer=t;
    full=true;
	}
	catch(const char* msg)
	{
		std::cout<<msg;
	}
}

Token Token_stream::get()
{
	try
	{
		if (full)
		{
			full=false;
			return buffer;
		}
		char ch;
		std::cin>>ch;
		switch (ch)
		{
		case '=':
        case 'x':
        case '(':
        case ')':
        case '{':
        case '}':
        case '+':
        case '-':
        case '*':
        case '/':
            return Token{ch};
        case '.':
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
        {
        	std::cin.putback(ch);
            double val;
            std::cin>>val;
            return Token{'8', val};
        }
        default:
            throw "Bad Token";
		}
	}
	catch(const char* msg)
	{
		std::cout<<msg;
	}
}
Token_stream ts;

double expression();

double primary()
{
	try
	{
		Token t=ts.get();
		switch (t.kind) {
		case '(':
        {
            double d=expression();
            t=ts.get();
            if (t.kind!=')')
            	throw "')' expected";
            return d;
        }
		case '{':
		{
			double d=expression();
			t=ts.get();
			if (t.kind!='}')
				throw "'}' expected";
			return d;
		}
		case '8':
			return t.value;
		default:
			throw "primary expected";
		}
	}
	catch(const char* msg)
	{
		std::cout<<msg;
	}
}

double term()
{
	try
	{
		double left=primary();
		Token t=ts.get();

		while(true)
		{
			switch (t.kind)
			{
			case '*':
				left*=primary();
				t=ts.get();
				break;
			case '/':
			{
                double d=primary();
                if (d==0)
                	throw "divide by zero";
                left/=d;
                t=ts.get();
                break;
            }
			default:
				ts.putback(t);
				return left;
			}
		}
    }
	catch(const char* msg)
	{
		std::cout<<msg;
	}
}

double expression()
{
    double left=term();
    Token t=ts.get();
    while(true)
    {
        switch(t.kind)
        {
        case '+':
            left+=term();
            t=ts.get();
            break;
        case '-':
            left-=term();
            t=ts.get();
            break;
        default:
            ts.putback(t);
            return left;
        }
    }
}

int main()
{
	try
	{
		std::cout<<"Welcome to the calculator!\nEnter floating point expressions.\n";
		std::cout<<"Please, enter expressions with operators '+', '-', '*' and '/'.\n";
		std::cout<<"After expression enter operator '=' and you'll see answer.\n";
		std::cout<<"For exit program - enter 'x'.\n";
		double val=0;
		while (std::cin)
		{
			Token t=ts.get();
			if (t.kind=='x')
				break;
			if (t.kind=='=')
				std::cout<<""<<val<<"\n";
			else
				ts.putback(t);
			val=expression();
		}
	}
	catch (...)
	{
    std::cerr<<"Oops: unknown exception!\n";
    return 1;
	}
}
