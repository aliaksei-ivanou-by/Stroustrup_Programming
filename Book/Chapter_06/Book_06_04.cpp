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
        Token get();
        void putback(Token t);
    private:
        bool full {false};
        Token buffer={'0'};
};

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
		case ';':
        case 'q':
        case '(':
        case ')':
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

double term();

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

int main()
try
{
    while (std::cin)
        std::cout<<expression()<<"\n";
}
catch (...)
{
    std::cerr<<"exception \n";
    return 1;
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
