#pragma once
#include <iostream>
#include <fstream>

class Test
{
public:
	std::string label;
	std::string command;
	std::string argument01;
	std::string argument02;
	int result;
	friend std::istream& operator>> (std::istream& inputStream, Test& test)
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
		std::string labelForAdd;
		std::string commandForAdd;
		std::string argument01ForAdd;
		std::string argument02ForAdd;
		int resultForAdd;
		inputStream >> labelForAdd >> commandForAdd >> argument01ForAdd >> argument02ForAdd >> resultForAdd;
		inputStream >> delimeter2;
		if (delimeter2 != '}')
		{
			return inputStream;
		}
		test.label = labelForAdd;
		test.command = commandForAdd;
		test.argument01 = argument01ForAdd;
		test.argument02 = argument02ForAdd;
		test.result = resultForAdd;
		return inputStream;
	}
};

class Document_Test
{
private:
	Document document;
	std::vector<Test> tests;
	void set(std::istream& inputStream)
	{
		inputStream >> document;
	}
	void setDocument(std::istream& inputStream)
	{
		inputStream >> document;
	}
	void setTests(std::istream& inputStream)
	{
		Test test;
		while (inputStream >> test)
		{
			tests.push_back(test);
		}
	}
	void run()
	{
		int result = 0;
		int testsPassed = 0;
		int testsFailed = 0;
		for (std::size_t i = 0; i < tests.size(); ++i)
		{
			std::string command = tests[i].command;
			if (command == "find_text")
			{
				auto it = document.find_text(tests[i].argument01);
				it != document.end() ? result = 1 : result = 0;
			}
			else
			{
				if (command == "count_chars")
				{
					result = document.count_chars();
				}
				else
				{
					if (command == "count_words")
					{
						result = document.count_words_1();
					}
					else
					{
						if (command == "find_replace_text")
						{
							auto it = document.find_replace_text(tests[i].argument01, tests[i].argument02);
							it != document.end() ? result = 1 : result = 0;
						}
						else
						{}
					}
				}
			}
			if (result != tests[i].result)
			{
				std::cout << "Test: " << tests[i].label << " expected: " << tests[i].result << ", from real data: " << result << '\n';
				++testsFailed;
			}
			else
			{
				++testsPassed;
			}
		}
		std::cout << "\n\nRESULT\n";
		std::cout << "Passed tests = " << testsPassed << '\n';
		std::cout << "Failes tests = " << testsFailed << '\n';
	}
public:
	Document_Test() = delete;
	Document_Test(std::istream& inputStreamNameDocument, std::istream& inputStreamNameDocumentTests)
	{
		setDocument(inputStreamNameDocument);
		setTests(inputStreamNameDocumentTests);
		run();
	}
};
