#pragma once
#include <iostream>
#include <vector>
#include <cmath>

constexpr char let = 'L';
constexpr char con = 'C';
constexpr char quit = 'q';
constexpr char help = 'h';
constexpr char print = ';';
constexpr char number = '8';
constexpr char name = 'a';
constexpr char square_root = 's';
constexpr char power = 'p';
const std::string declkey = "let";
const std::string conkey = "const";
const std::string sqrtkey = "sqrt";
const std::string powkey = "pow";
const std::string quitkey = "quit";
const std::string helpkey = "help";
const std::string prompt = "> ";
const std::string result = "= ";

class Token
{
public:
	char kind;
	int value;
	std::string name;
	Token(char ch);
	Token(char ch, int val);
	Token(char ch, std::string n);
};

class Token_stream
{
public:
	Token_stream();
	Token_stream(std::istream& inputStream);
	Token get();
	void putback(Token t);
	void ignore(char c);
private:
	bool full;
	Token buffer;
	std::istream& inputTokenStream;
};

class Variable
{
public:
	std::string name;
	int value;
	bool is_const;
	Variable(std::string n, int v, bool b);
};

class Symbol_table
{
public:
	int get(std::string s);
	void set(std::string s, int d);
	bool is_declared(std::string var);
	int declare(std::string var, int val, bool b);
private:
	std::vector<Variable> var_table;
};

Symbol_table st;

int expression(Token_stream& tokenStream);
int my_pow(int base, int expo);
int primary(Token_stream& tokenStream);
int term(Token_stream& tokenStream);
int declaration(Token_stream& tokenStream, bool b);
int statement(Token_stream& tokenStream);
void clean_up_mess(Token_stream& tokenStream);
void print_help(std::ostream& outputStream);
void calculate(
	Token_stream& tokenStream,
	std::ostream& outputStream = std::cout,
	std::ostream& outputStreamErrors = std::cerr);

// class Token

Token::Token(char ch):
	kind{ ch },
	value{ 0 }
{}

Token::Token(char ch, int val):
	kind{ ch },
	value{ val }
{}

Token::Token(char ch, std::string n):
	kind{ ch },
	name{ n }
{}

// class Token_stream

Token_stream::Token_stream():
	full{ false },
	buffer{ 0 }, 
	inputTokenStream{ std::cin }
{}

Token_stream::Token_stream(std::istream& inputStream):
	full{ false },
	buffer{ 0 },
	inputTokenStream{ inputStream }
{}

Token Token_stream::get()
try
{
	if (full)
	{
		full = false;
		return buffer;
	}
	char ch;
	inputTokenStream.get(ch);
	while (isspace(ch))
	{
		if (inputTokenStream.eof())
		{
			return Token(print);
		}
		inputTokenStream.get(ch);
	}
	switch (ch)
	{
	case 'H':
	{
		return Token(help);
	}
	case help: case quit: case print:
	case '(': case ')': case '+': case '-': case '*': case '&': case '~':
	case '/': case '%': case '=': case ',': case '|': case '^':
	{
		return Token(ch);
	}
	case '.':
	case '0': case '1': case '2': case '3': case '4':
	case '5': case '6': case '7': case '8': case '9':
	{
		inputTokenStream.putback(ch);
		int val;
		inputTokenStream >> val;
		return Token(number, val);
	}
	default:
	{
		if (isalpha(ch))
		{
			std::string s;
			s += ch;
			while (inputTokenStream.get(ch) && (isalpha(ch) || isdigit(ch) || ch == '_'))
			{
				s += ch;
			}
			inputTokenStream.putback(ch);
			if (s == declkey)
			{
				return Token(let);
			}
			if (s == conkey)
			{
				return Token(con);
			}
			if (s == sqrtkey)
			{
				return Token(square_root);
			}
			if (s == powkey)
			{
				return Token(power);
			}
			if (s == helpkey)
			{
				return Token(help);
			}
			if (s == quitkey)
			{
				return Token(quit);
			}
			return Token(name, s);
		}
	}
	throw ("Bad token\n");
	}
}
catch (const char* msg)
{
	std::cout << msg;
}


void Token_stream::putback(Token t)
try
{
	if (full)
	{
		throw ("Putback() into full buffer\n");
	}
	buffer = t;
	full = true;
}
catch (const char* msg)
{
	std::cout << msg;
}


void Token_stream::ignore(char c)
{
	if (full && c == buffer.kind)
	{
		full = false;
		return;
	}
	full = false;
	char ch = 0;
	while (inputTokenStream >> ch)
	{
		if (ch == c)
		{
			return;
		}
	}
}

// class Variable

Variable::Variable(std::string n, int v, bool b):
	name{ n },
	value{ v },
	is_const{ b }
{}

// class Symbol_table

int Symbol_table::get(std::string s)
try
{
	for (int i = 0; i < var_table.size(); ++i)
	{
		if (var_table[i].name == s)
		{
			return var_table[i].value;
		}
	}
	throw ("Get: undefined variable\n");
}
catch (const char* msg)
{
	std::cout << msg;
}


void Symbol_table::set(std::string s, int d)
try
{
	for (int i = 0; i < var_table.size(); ++i)
	{
		if (var_table[i].name == s)
		{
			if (var_table[i].is_const)
			{
				throw ("Variable is a constant\n");
			}
			var_table[i].value = d;
			return;
		}
	}
	throw ("Set: undefined variable\n");
}
catch (const char* msg)
{
	std::cout << msg;
}


bool Symbol_table::is_declared(std::string var)
{
	for (int i = 0; i<int(var_table.size()); ++i)
	{
		if (var_table[i].name == var)
		{
			return true;
		}
	}
	return false;
}

int Symbol_table::declare(std::string var, int val, bool b)
try
{
	if (is_declared(var))
	{
		throw ("Variable declared twice\n");
	}
	var_table.push_back(Variable(var, val, b));
	return val;
}
catch (const char* msg)
{
	std::cout << msg;
}


int my_pow(int base, int expo)
{
	if (expo == 0)
	{
		if (base == 0)
		{
			return 0;
		}
		return 1;
	}
	int res = base;
	for (int i = 2; i <= expo; ++i)
	{
		res *= base;
	}
	return res;
}

int primary(Token_stream& ts)
try
{
	Token t = ts.get();
	switch (t.kind)
	{
	case '(':
	{
		int d = expression(ts);
		t = ts.get();
		if (t.kind != ')')
		{
			throw ("')' expected\n");
		}
		return d;
	}
	case '-':
	{
		return -primary(ts);
	}
	case '+':
	{
		return primary(ts);
	}
	case '~':
	{
		return ~primary(ts);
	}
	case number:
	{
		return t.value;
	}
	case name:
	{
		Token t2 = ts.get();
		if (t2.kind == '=')
		{
			int d = expression(ts);
			st.set(t.name, d);
			return d;
		}
		else
		{
			ts.putback(t2);
			return st.get(t.name);
		}
	}
	case square_root:
	{
		t = ts.get();
		if (t.kind != '(')
		{
			throw ("'(' expected\n");
		}
		int d = expression(ts);
		if (d < 0)
		{
			throw ("Square roots of negative numbers... nope!\n");
		}
		t = ts.get();
		if (t.kind != ')')
		{
			throw ("')' expected\n");
		}
		double root = sqrt(d);
		if (int(root) != root)
		{
			throw ("SQRT operation resulted in non-integer value\n");
		}
		return int(root);
	}
	case power:
	{
		t = ts.get();
		if (t.kind != '(')
		{
			throw ("'(' expected\n");
		}
		int d = expression(ts);
		t = ts.get();
		if (t.kind != ',')
		{
			throw ("',' expected\n");
		}
		t = ts.get();
		if (t.kind != number)
		{
			throw ("Second argument of 'pow' is not a number\n");
		}
		int i = int(t.value);
		if (i != t.value)
		{
			throw ("Second argument of 'pow' is not an integer\n");
		}
		t = ts.get();
		if (t.kind != ')')
		{
			throw ("')' expected");
		}
		return my_pow(d, i);
	}
	default:
	{
		throw ("Primary expected");
	}
	}
}
catch (const char* msg)
{
	std::cout << msg;
}


int term(Token_stream& ts)
try
{
	int left = primary(ts);
	Token t = ts.get();
	while (true)
	{
		switch (t.kind)
		{
		case '*':
		{
			left *= primary(ts);
			t = ts.get();
			break;
		}
		case '/':
		{
			int d = primary(ts);
			if (d == 0)
			{
				throw ("Divide by zero\n");
			}
			left /= d;
			int left_int = int(left);
			if (left_int != left)
			{
				throw ("Division led to non-integer value\n");
			}
			t = ts.get();
			break;
		}
		case '%':
		{
			int d = primary(ts);
			int i1 = int(left);
			if (i1 != left)
			{
				throw ("Left-hand operand of % not int\n");
			}
			int i2 = int(d);
			if (i2 != d)
			{
				throw ("Right-hand operand of % not int\n");
			}
			if (i2 == 0)
			{
				throw ("%: divide by zero\n");
			}
			left = i1 % i2;
			t = ts.get();
			break;
		}
		default:
		{
			ts.putback(t);
			return left;
		}
		}
	}
}
catch (const char* msg)
{
	std::cout << msg;
}


int expression(Token_stream& ts)
try
{
	int left = term(ts);
	Token t = ts.get();
	while (true)
	{
		switch (t.kind)
		{
		case '+':
		{
			left += term(ts);
			t = ts.get();
			break;
		}
		case '-':
		{
			left -= term(ts);
			t = ts.get();
			break;
		}
		case '&':
		{
			left &= term(ts);
			t = ts.get();
			break;
		}
		case '|':
		{
			left |= term(ts);
			t = ts.get();
			break;
		}
		case '^':
		{
			left ^= term(ts);
			t = ts.get();
			break;
		}
		case '=':
		{
			throw ("Use of '=' outside of a declaration\n");
		}
		default:	
		{
			ts.putback(t);
			return left;
		}
		}
	}
}
catch (const char* msg)
{
	std::cout << msg;
}


int declaration(Token_stream& tokenStream, bool b)
try
{
	Token t = tokenStream.get();
	if (t.kind != name)
	{
		throw ("Name expected in declaration\n");
	}
	std::string var_name = t.name;
	Token t2 = tokenStream.get();
	if (t2.kind != '=')
	{
		throw ("= missing in declaration\n");
	}
	int d = expression(tokenStream);
	st.declare(var_name, d, b);
	return d;
}
catch (const char* msg)
{
	std::cout << msg;
}


int statement(Token_stream& tokenStream)
{
	Token t = tokenStream.get();
	switch (t.kind)
	{
	case let:
	{
		return declaration(tokenStream, false);
	}
	case con:
	{
		return declaration(tokenStream, true);
	}
	default:
	{
		tokenStream.putback(t);
		return expression(tokenStream);
	}
	}
}

void clean_up_mess(Token_stream& tokenStream)
{
	tokenStream.ignore(print);
}

void print_help(std::ostream& outputStream)
{
	outputStream << "Instructions: enter expressions, there are\n";
	outputStream << "a few functions, you can declare variables using\n";
	outputStream << "the 'let' keyword and constants with the 'const'\n";
	outputStream << "keyword.\n";
}

void calculate(Token_stream& tokenStream, std::ostream& outputStream, std::ostream& outputStreamErrors)
{
	while (true)
	{
		try
		{
			outputStream << statement(tokenStream) << std::endl;
			Token token = tokenStream.get();
			while (token.kind == print)
			{
				return;
			}
		}
		catch (const std::exception& e)
		{
			outputStreamErrors << "Exception occured: " << e.what() << '\n';
			clean_up_mess(tokenStream);
		}
		catch (...)
		{
			outputStreamErrors << "Unknown exception occured\n";
		}
	}
}