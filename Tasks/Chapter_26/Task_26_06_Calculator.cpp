#include <iostream>
#include <vector>
#include <cmath>
#include "Task_26_06_Calculator.h"
#include "Task_26_06_Calculator_Test.h"

int main()
try
{
	std::string fileNameTests("Task_26_06_Tests.txt");
	std::string fileNameInput("Task_26_06_Input.txt");
	std::string fileNameResult("Task_26_06_Result.txt");

	std::ifstream inputFileStreamTests(fileNameTests);
	std::ifstream inputFileStreamInput(fileNameInput);
	std::ofstream inputFileStreamResult(fileNameResult);

	if (!inputFileStreamTests || !inputFileStreamInput)
	{
		throw std::runtime_error("Can't open file!\n");
	}

	std::vector<Test<double>> conditions;
	std::vector<std::string> expressions;

	get_tests(inputFileStreamTests, conditions);
	get_expressions(inputFileStreamInput, expressions);

	if (run<double>(conditions, expressions, inputFileStreamResult))
	{
		std::cout << "Tests passed.\n";
	}
	else
	{
		std::cout << "Tests NOT passed!\n";
	}
}
catch (const std::exception& e)
{
	std::cerr << "Exception occured: " << e.what() << '\n';
	return 1;
}
catch (...)
{
	return 2;
}
