#include "iostream"
#include "vector"
#include "cmath"
#include "Task_10_07(6).h"

static int error_num=0;

const char let='L';
const char quit='q';
const char print=';';
const char number='8';
const char name='a';
const std::string declkey="let";
const std::string prompt="> ";
const std::string result="= ";

class Token
{
public:
	char kind;
	Roman_int value;;
	std::string name;
	Token(char ch) :kind(ch), value(0) {}
	Token(char ch, Roman_int val) :kind(ch), value(val) {}
    Token(char ch, std::string n) :kind(ch), name(n) {}
};

class Token_stream
{
public:
    Token_stream();
	Token get();
    void putback(Token t);
    void ignore(char c);
private:
	bool full;
	Token buffer;
};

Token_stream::Token_stream() :full(false), buffer(0) {}

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
		case quit:
		case print:
		case '(':
		case ')':
		case '+':
		case '-':
		case '*':
		case '/':
		case '%':
		case '=':
		case ',':
			return Token(ch);
		case N: case I: case V: case X:
		case L: case C: case D: case M:
		{
			std::cin.putback(ch);
			Roman_int val;
			std::cin>>val;
			return Token(number,val);
		}
		default:
			if (isalpha(ch))
			{
				std::string s;
				s+=ch;
				while (std::cin.get(ch) && (isalpha(ch) || isdigit(ch)))
					s+=ch;
				std::cin.putback(ch);
				if (s==declkey)
					return Token(let);
				return Token(name,s);
			}
			throw "Bad token\n";
		}
	}
	catch(const char* msg)
	{
		std::cout<<msg;
	}
}

void Token_stream::putback(Token t)
{
	try
	{
		if (full)
			throw "Putback() into full buffer\n";
		buffer=t;
		full=true;
	}
	catch(const char* msg)
	{
		if (error_num==0)
			std::cout<<msg;
		error_num++;
	}
}

void Token_stream::ignore(char c)
{
	if (full && c==buffer.kind)
	{
		full=false;
		return;
	}
	full=false;
	char ch=0;
	while (std::cin>>ch)
		if (ch==c)
			return;
}

class Variable
{
public:
	std::string name;
	Roman_int value;
	Variable(std::string n, Roman_int v) :name(n), value(v) {}
};

std::vector<Variable> var_table;

Token_stream ts;

Roman_int get_value(std::string s)
try
{
    for (int i=0; i<var_table.size(); ++i)
    	if (var_table[i].name==s)
    		return var_table[i].value;
    throw "get: undefined variable\n";
}
catch(const char* msg)
{
	std::cout<<msg;
}

void set_value(std::string s, Roman_int d)
try
{
	for (int i=0; i<var_table.size(); ++i)
		if (var_table[i].name==s)
		{
			var_table[i].value=d;
			return;
        }
	throw "set: undefined variable\n";
}
catch(const char* msg)
{
	std::cout<<msg;
}

bool is_declared(std::string var)
{
	for (int i=0; i<var_table.size(); ++i)
		if (var_table[i].name==var)
			return true;
    return false;
}

Roman_int define_name(std::string var, Roman_int val)
try
{
	if (is_declared(var))
		throw "value declared twice\n";
	var_table.push_back(Variable(var, val));
    return val;
}
catch(const char* msg)
{
	std::cout<<msg;
}

Roman_int expression();

Roman_int primary()
{
	try
	{
		Token t=ts.get();
		switch(t.kind)
		{
		case '(':
		{
			Roman_int d=expression();
			t=ts.get();
			if (t.kind!=')')
				throw "')' expected\n";
			return d;
		}
		case '-':
			return -primary();
		case '+':
			return primary();
		case number:
			return t.value;
		case name:
		{
			return t.value;
		}
		default:
			throw "Primary expected";
		}
	}
	catch(const char* msg)
	{
		if (error_num==0)
			std::cout<<msg;
		error_num++;
	}
}

Roman_int term()
{
	try
	{
		Roman_int left=primary();
		Token t=ts.get();
		while(true)
		{
			switch(t.kind)
			{
			case '*':
				left=left*primary();
				t=ts.get();
				break;
			case '/':
			{
				Roman_int d=primary();
				if (d==Roman_int(0))
					throw "Divide by zero\n";
				left=left/d;
				t=ts.get();
				break;
			}
			case '%':
			{
				Roman_int i1=left;
				Roman_int i2=term();
				if (i2==0)
					throw "%: divide by zero\n";
				left=i1%i2;
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
		if (error_num==0)
			std::cout<<msg;
		error_num++;
	}
}

Roman_int expression()
{
	try
	{
		Roman_int left=term();
		Token t=ts.get();
		while (true)
		{
			switch(t.kind)
			{
			case '+':
				left=left+term();
				t=ts.get();
				break;
			case '-':
				left=left-term();
				t=ts.get();
				break;
			default:
				ts.putback(t);
				return left;
			}
		}
	}
	catch(const char* msg)
	{
		if (error_num==0)
			std::cout<<msg;
		error_num++;
	}
}

Roman_int declaration(bool b)
{
	try
	{
		Token t=ts.get();
		if (t.kind!=name)
			throw "Name expected in declaration\n";
		std::string var_name=t.name;
		Token t2=ts.get();
		if (t2.kind!='=')
			throw "= missing in declaration\n";
		Roman_int d=expression();
		define_name(var_name, d);
		return d;
	}
	catch(const char* msg)
	{
		if (error_num==0)
			std::cout<<msg;
		error_num++;
	}
}

Roman_int statement()
{
	Token t=ts.get();
	switch(t.kind)
	{
	case let:
		return declaration(false);
	default:
		ts.putback(t);
		return expression();
	}
}

void clean_up_mess()
{
	ts.ignore(print);
}

void calculate()
{
	while (std::cin)
    try
	{
    	std::cout<<prompt;
    	Token t=ts.get();
    	while (t.kind==print)
    		t=ts.get();
    	if (t.kind==quit)
    		return;
    	ts.putback(t);
    	std::cout<<result<<statement()<<"\n";
	}
	catch(const char* msg)
	{
		if (error_num==0)
			std::cout<<msg;
		error_num++;
		clean_up_mess();
	}
}

int main()
{
	try
	{
		error_num=0;
		calculate();
		return 0;
	}
	catch(...)
	{
		 std::cerr<<"Exception\n";
		 return 1;
	}
}
