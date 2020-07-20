#ifndef TASK_16_09_TOKEN_H
#define TASK_16_09_TOKEN_H

#ifndef Task_16_09_STDAFX_H
#include "Task_16_09_stdafx.h"
#endif

namespace Calc_lib
{
	const char let = 'L';
	const char con = 'C';
	const char number = '8';
	const char name = 'a';
	const char square_root = 's';
	const char power = 'p';
	const std::string declkey = "let";
	const std::string conkey = "const";
	const std::string sqrtkey = "sqrt";
	const std::string powkey = "pow";

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
		Token_stream(string);
		Token get();
		void putback(Token t);
		void ignore(char c);
	private:
		bool full;
		Token buffer;
		istringstream iss;
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
		vector<Variable> var_table;
	};

	class Calculator
	{
	public:
		Calculator();
		string calculate(string input);
	private:
		double primary(Token_stream& ts);
		double term(Token_stream& ts);
		double expression(Token_stream& ts);
		double declaration(bool b, Token_stream& ts);
		double statement(Token_stream& ts);
		Symbol_table st;
	};
}

#endif