#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

template<typename T>
struct Test
{
	std::string label;
	T result;
};

template<typename T>
std::istream& operator>>(std::istream& inputStream, Test<T>& test)
{
	if (!inputStream)
	{
		return inputStream;
	}
	char delimeter1;
	char delimeter2;
	inputStream >> delimeter1;
	if (delimeter1 != '{')
	{
		return inputStream;
	}
	std::string label;
	T result;
	inputStream >> label >> result >> delimeter2;
	if (!inputStream)
	{
		return inputStream;
	}
	if (delimeter2 != '}')
	{
		return inputStream;
	}
	test.label = label;
	test.result = result;
	return inputStream;
}

template <typename T>
void get_tests(std::istream& inputStream, std::vector<Test<T>>& tests)
{
	Test<T> test;
	while (inputStream >> test)
	{
		tests.emplace_back(test);
	}
}

void get_expressions(std::istream& inputStream, std::vector<std::string>& expressions)
{
	std::string expression;
	while (getline(inputStream, expression))
	{
		expressions.emplace_back(expression);
	}
}

template <typename T>
bool run(
	std::vector<Test<T> >& tests,
	std::vector<std::string>& expressions,
	std::ofstream& inputFileStreamResult)
{
	bool success = true;
	int tests_failed = 0;
	int tests_passed = 0;
	int tests_all = 0;
	for (size_t i = 0; i < tests.size(); ++i)
	{
		for (size_t j = 0; j < expressions.size(); ++j)
		{
			std::stringstream inputStream(expressions[j]);
			std::stringstream outputStream;
			Token_stream tokenStream(inputStream);
			calculate(tokenStream, outputStream);
			T result;
			outputStream >> result;
			if (result != tests[i].result)
			{
				++tests_failed;
				inputFileStreamResult << "Test " << tests[i].label <<
					" expected result = " << tests[i].result <<
					", result from experiment (expression " << j + 1 << ") = " <<
					result << '\n';
				success = false;
			}
			else
			{
				++tests_passed;
			}
			++tests_all;
		}
	}
	inputFileStreamResult << "All tests: " << tests_all <<
		"\tPassed: " << tests_passed <<
		"\tFailed: " << tests_failed << '\n';
	inputFileStreamResult.close();
	return success;
}