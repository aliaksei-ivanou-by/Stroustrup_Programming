#pragma once
#include <iostream>
#include <vector>
#include <cmath>

int error_num = 0;

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
	Token get();
	void putback(Token t);
	void ignore(char c);
private:
	bool full;
	Token buffer;
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

Token_stream ts;
Symbol_table st;

int expression();
int my_pow(int base, int expo);
int primary();
int term();
int declaration(bool b);
int statement();
void clean_up_mess();
void print_help();
void calculate();

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
	buffer{ 0 }
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
	std::cin.get(ch);
	while (isspace(ch))
	{
		if (ch == '\n')
		{
			return Token(print);
		}
		std::cin.get(ch);
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
		std::cin.putback(ch);
		int val;
		std::cin >> val;
		return Token(number, val);
	}
	default:
	{
		if (isalpha(ch))
		{
			std::string s;
			s += ch;
			while (std::cin.get(ch) && (isalpha(ch) || isdigit(ch) || ch == '_'))
			{
				s += ch;
			}
			std::cin.putback(ch);
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
	if (error_num == 0)
	{
		std::cout << msg;
	}
	error_num++;
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
	while (std::cin >> ch)
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
	if (error_num == 0)
	{
		std::cout << msg;
	}
	error_num++;
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
	if (error_num == 0)
	{
		std::cout << msg;
	}
	error_num++;
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
	if (error_num == 0)
	{
		std::cout << msg;
	}
	error_num++;
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

int primary()
try
{
	Token t = ts.get();
	switch (t.kind)
	{
	case '(':
	{
		int d = expression();
		t = ts.get();
		if (t.kind != ')')
		{
			throw ("')' expected\n");
		}
		return d;
	}
	case '-':
	{
		return -primary();
	}
	case '+':
	{
		return primary();
	}
	case '~':
	{
		return ~primary();
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
			int d = expression();
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
		int d = expression();
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
		int d = expression();
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
	if (error_num == 0)
	{
		std::cout << msg;
	}
	error_num++;
}

int term()
try
{
	int left = primary();
	Token t = ts.get();
	while (true)
	{
		switch (t.kind)
		{
		case '*':
		{
			left *= primary();
			t = ts.get();
			break;
		}
		case '/':
		{
			int d = primary();
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
			int d = primary();
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
	if (error_num == 0)
	{
		std::cout << msg;
	}
	error_num++;
}

int expression()
try
{
	int left = term();
	Token t = ts.get();
	while (true)
	{
		switch (t.kind)
		{
		case '+':
		{
			left += term();
			t = ts.get();
			break;
		}
		case '-':
		{
			left -= term();
			t = ts.get();
			break;
		}
		case '&':
		{
			left &= term();
			t = ts.get();
			break;
		}
		case '|':
		{
			left |= term();
			t = ts.get();
			break;
		}
		case '^':
		{
			left ^= term();
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
	if (error_num == 0)
	{
		std::cout << msg;
	}
	error_num++;
}

int declaration(bool b)
try
{
	Token t = ts.get();
	if (t.kind != name)
	{
		throw ("Name expected in declaration\n");
	}
	std::string var_name = t.name;
	Token t2 = ts.get();
	if (t2.kind != '=')
	{
		throw ("= missing in declaration\n");
	}
	int d = expression();
	st.declare(var_name, d, b);
	return d;
}
catch (const char* msg)
{
	if (error_num == 0)
	{
		std::cout << msg;
	}
	error_num++;
}

int statement()
{
	Token t = ts.get();
	switch (t.kind)
	{
	case let:
	{
		return declaration(false);
	}
	case con:
	{
		return declaration(true);
	}
	default:
	{
		ts.putback(t);
		return expression();
	}
	}
}

void clean_up_mess()
{
	ts.ignore(print);
}

void print_help()
{
	std::cout << "Instructions: enter expressions, there are\n";
	std::cout << "a few functions, you can declare variables using\n";
	std::cout << "the 'let' keyword and constants with the 'const'\n";
	std::cout << "keyword.\n";
}

void calculate()
{
	while (std::cin)
	{
		try
		{
			std::cout << prompt;
			Token t = ts.get();
			while (t.kind == print)
			{
				t = ts.get();
			}
			if (t.kind == help)
			{
				print_help();
			}
			else
			{
				if (t.kind == quit)
				{
					return;
				}
				ts.putback(t);
				std::cout << result << statement() << "\n";
			}
		}
		catch (const char* msg)
		{
			if (error_num == 0)
			{
				std::cout << msg;
			}
			error_num++;
			clean_up_mess();
		}
	}
}