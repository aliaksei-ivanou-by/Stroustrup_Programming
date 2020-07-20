#ifndef TASK_16_09_STDAFX_H
#include "Task_16_09_stdafx.h"
#include "Task_16_09_Calculator.h"
#endif

Calc_lib::Token::Token(char ch)
	: kind{ ch }, 
	value{ 0 }
{
}

Calc_lib::Token::Token(char ch, int val)
	: kind{ ch }, 
	value{ val }
{
}

Calc_lib::Token::Token(char ch, std::string n)
	: kind{ ch }, 
	name{ n }
{
}

Calc_lib::Token_stream::Token_stream()
	: full{ false },
	buffer{ 0 }
{
}

Calc_lib::Token_stream::Token_stream(string str)
	: full{ false },
	buffer{ 0 },
	iss{ str }
{
}

Calc_lib::Token Calc_lib::Token_stream::get()
{
	if (full)
	{
		full = false;
		return buffer;
	}
	char ch;
	iss.get(ch);
	while (isspace(ch))
	{
		iss.get(ch);
	}
	switch (ch)
	{
	case '(':
	case ')':
	case '+':
	case '-':
	case '*':
	case '/':
	case '%':
	case '=':
	case ',':
	{
		return Token(ch);
	}
	case '.':
	case '0': case '1': case '2': case '3': case '4':
	case '5': case '6': case '7': case '8': case '9':
	{
		iss.putback(ch);
		int val;
		iss >> val;
		return Token(number, val);
	}
	default:
	{
		if (isalpha(ch))
		{
			std::string s;
			s += ch;
			while (iss.get(ch) && (isalpha(ch) || isdigit(ch) || ch == '_'))
			{
				s += ch;
			}
			iss.putback(ch);
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
			return Token(name, s);
		}
	}
	error("Bad token");
	}
}

void Calc_lib::Token_stream::putback(Token t)
{
	if (full)
	{
		error("Putback() into full buffer");
	}
	buffer = t;
	full = true;
}

void Calc_lib::Token_stream::ignore(char c)
{
	if (full && c == buffer.kind)
	{
		full = false;
		return;
	}
	full = false;
	char ch = 0;
	while (iss >> ch)
	{
		if (ch == c)
		{
			return;
		}
	}
}

Calc_lib::Variable::Variable(std::string n, int v, bool b)
	: name{ n },
	value{ v },
	is_const{ b }
{
}

int Calc_lib::Symbol_table::get(std::string s)
{
	for (int i = 0; i < var_table.size(); ++i)
	{
		if (var_table[i].name == s)
		{
			return var_table[i].value;
		}
	}
	error("Get: undefined variable", s);
}

void Calc_lib::Symbol_table::set(std::string s, int d)
{
	for (int i = 0; i < var_table.size(); ++i)
	{
		if (var_table[i].name == s)
		{
			if (var_table[i].is_const)
			{
				error(s, " is a constant");
			}
			var_table[i].value = d;
			return;
		}
	}
	error("Set: undefined variable ", s);
}

bool Calc_lib::Symbol_table::is_declared(std::string var)
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

int Calc_lib::Symbol_table::declare(std::string var, int val, bool b)
{
	if (is_declared(var))
	{
		error(var, " declared twice");
	}
	var_table.push_back(Variable(var, val, b));
	return val;
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

Calc_lib::Calculator::Calculator()
{
	st.declare("pi", 3.141592653589, true);
}

string Calc_lib::Calculator::calculate(string input)
{
	Token_stream ts(input);
	ostringstream oss;
	oss << statement(ts);
	return oss.str();
}

double Calc_lib::Calculator::primary(Token_stream& ts)
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
			error("')' expected");
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
			error("'(' expected");
		}
		int d = expression(ts);
		if (d < 0)
		{
			error("Square roots of negative numbers... nope!");
		}
		t = ts.get();
		if (t.kind != ')')
		{
			error("')' expected");
		}
		double root = sqrt(d);
		if (int(root) != root)
		{
			error("SQRT operation resulted in non-integer value");
		}
		return int(root);
	}
	case power:
	{
		t = ts.get();
		if (t.kind != '(')
		{
			error("'(' expected");
		}
		int d = expression(ts);
		t = ts.get();
		if (t.kind != ',')
		{
			error("',' expected");
		}
		t = ts.get();
		if (t.kind != number)
		{
			error("Second argument of 'pow' is not a number");
		}
		int i = int(t.value);
		if (i != t.value)
		{
			error("Second argument of 'pow' is not an integer");
		}
		t = ts.get();
		if (t.kind != ')')
		{
			error("')' expected");
		}
		return my_pow(d, i);
	}
	default:
	{
		error("Primary expected");
	}
	}
}

double Calc_lib::Calculator::term(Token_stream& ts)
{
	double left = primary(ts);
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
			double d = primary(ts);
			if (d == 0)
			{
				error("Divide by zero");
			}
			left /= d;
			t = ts.get();
			break;
		}
		case '%':
		{
			double d = primary(ts);
			int i1 = int(left);
			if (i1 != left)
			{
				error("Left-hand operand of % not int");
			}
			int i2 = int(d);
			if (i2 != d)
			{
				error("Right-hand operand of % not int");
			}
			if (i2 == 0)
			{
				error("%: divide by zero");
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

double Calc_lib::Calculator::expression(Token_stream& ts)
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
		case '=':
		{
			error("Use of '=' outside of a declaration");
		}
		default:
		{
			ts.putback(t);
			return left;
		}
		}
	}
}

double Calc_lib::Calculator::declaration(bool b, Token_stream& ts)
{
	Token t = ts.get();
	if (t.kind != name)
	{
		error("Name expected in declaration");
	}
	std::string var_name = t.name;
	Token t2 = ts.get();
	if (t2.kind != '=')
	{
		error("= missing in declaration");
	}
	int d = expression(ts);
	st.declare(var_name, d, b);
	return d;
}

double Calc_lib::Calculator::statement(Token_stream& ts)
{
	Token t = ts.get();
	switch (t.kind)
	{
	case let:
	{
		return declaration(false, ts);
	}
	case con:
	{
		return declaration(true, ts);
	}
	default:
	{
		ts.putback(t);
		return expression(ts);
	}
	}
}