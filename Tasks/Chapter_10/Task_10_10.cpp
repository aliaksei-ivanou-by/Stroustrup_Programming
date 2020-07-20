#include "iostream"
#include "fstream"
#include "vector"
using namespace std;

std::string input="Task_10_10_input.txt";
std::ifstream ifs(input.c_str());
std::string output="Task_10_10_output.txt";
std::ofstream ofs(output.c_str());

const char number='8';
const char quit='q';
const char print=';';
const char name='a';
const char let='L';
const std::string declkey="let";
const std::string prompt="> ";
const std::string result="= ";

class Token
{
public:
    char kind;
    double value;
    std::string name;
    Token(char ch)
    	:kind(ch), value(0) {}
    Token(char ch, double val)
    	:kind(ch), value(val) {}
    Token(char ch, std::string n)
    	:kind(ch), name(n) {}
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

Token_stream::Token_stream()
    :full(false), buffer(0) {}

void Token_stream::putback(Token t)
{
    if (full)
    	 ofs<<"putback() into a full buffer"<<std::endl;
    buffer=t;
    full=true;
}

Token Token_stream::get()
{
    if (full)
    {
        full=false;
        return buffer;
    }
    char ch;
    ifs>>ch;
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
        return Token(ch);
    case '.':
    case '0': case '1': case '2': case '3': case '4':
    case '5': case '6': case '7': case '8': case '9':
    {
        ifs.putback(ch);
        double val;
        ifs>>val;
        return Token(number,val);
    }
    default:
        if (isalpha(ch))
        {
            std::string s;
            s+=ch;
            while (ifs.get(ch) && (isalpha(ch) || isdigit(ch)))
            	s+=ch;
            ifs.putback(ch);
            if (s==declkey)
            	return Token(let);
            return Token(name,s);
        }
        ofs<<"Bad token"<<std::endl;
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
    while (ifs>>ch)
        if (ch==c)
        	return;
}

Token_stream ts;

class Variable
{
public:
    std::string name;
    double value;
    Variable (std::string n, double v)
    	:name(n), value(v) {}
};

std::vector<Variable> var_table;

double get_value(std::string s)
{
    for (int i=0; i<var_table.size(); ++i)
        if (var_table[i].name==s)
        	return var_table[i].value;
    ofs<<"get: undefined variable "<<s<<std::endl;
}

void set_value(std::string s, double d)
{
    for (int i=0; i<var_table.size(); ++i)
        if (var_table[i].name==s)
        {
            var_table[i].value=d;
            return;
        }
    ofs<<"set: undefined variable "<<s<<std::endl;
}

bool is_declared(std::string var)
{
    for (int i=0; i<var_table.size(); ++i)
        if (var_table[i].name==var)
        	return true;
    return false;
}

double define_name(std::string var, double val)
{
    if (is_declared(var))
    	 ofs<<" declared twice"<<std::endl;
    var_table.push_back(Variable(var,val));
    return val;
}

double expression();

double primary()
{
    Token t=ts.get();
    switch (t.kind)
    {
    case '(':
    {
    	double d=expression();
        t=ts.get();
        if (t.kind != ')')
        	 ofs<<"')' expected"<<std::endl;
        return d;
    }
    case number:
        return t.value;
    case name:
        return get_value(t.name);
    case '-':
        return - primary();
    case '+':
        return primary();
    default:
    	ofs<<"primary expected"<<std::endl;
    }
}

double term()
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
            	ofs<<"divide by zero"<<std::endl;
            left/=d;
            t=ts.get();
            break;
        }
        case '%':
        {
        	int i1=int(left);
            int i2=int(term());
            if (i2==0)
            	ofs<<"%: divide by zero"<<std::endl;
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

double declaration()
{
    Token t=ts.get();
    if (t.kind!=name)
    	ofs<<"name expected in declaration"<<std::endl;
    string var_name=t.name;
    Token t2=ts.get();
    if (t2.kind!='=')
    	ofs<<"= missing in declaration of "<<var_name<<std::endl;
    double d=expression();
    define_name(var_name,d);
    return d;
}

double statement()
{
    Token t=ts.get();
    switch (t.kind)
    {
    case let:
        return declaration();
    default:
        ts.putback(t);
        return expression();
    }
}

void clean_up_mess()
{
    ts.ignore(print);
}

void calculate(std::ifstream& ifs, std::ofstream& ofs)
{
	while (ifs)
		try
		{
			ofs<<prompt;
			Token t=ts.get();
			while (t.kind==print)
				t=ts.get();
			if (t.kind == quit)
				return;
			ts.putback(t);
			ofs<<result<<statement()<<std::endl;
		}
		catch (exception& e)
		{
			ofs<<e.what()<<std::endl;
			clean_up_mess();
		}
}

int main()
try
{
    define_name("pi",3.1415926535);
    define_name("e",2.7182818284);
    calculate(ifs, ofs);
    return 0;
}
catch (std::exception& e)
{
    ofs<<e.what()<<std::endl;
    return 1;
}
catch (...)
{
    ofs<<"exception"<<std::endl;
    return 2;
}
