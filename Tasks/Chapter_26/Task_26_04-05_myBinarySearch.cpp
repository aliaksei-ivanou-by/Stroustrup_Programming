#include <iostream>
#include <fstream>
#include <vector>
#include "Task_26_04-05_myBinarySearch.h"


int main()
try
{
	{ // 4
		std::string fileNameSeq{ "Task_26_04_int.txt" };
		std::string fileNameTest{ "Task_26_04_int_test.txt" };
		std::cout << fileNameSeq << '\n';
		std::ifstream inputFileStreamSeq{ fileNameSeq };
		if (!inputFileStreamSeq)
		{
			throw std::runtime_error("Can't open file " + fileNameSeq);
		}
		std::ifstream inputFileStreamTest{ fileNameTest };
		if (!inputFileStreamTest)
		{
			throw std::runtime_error("Can't open file " + fileNameTest);
		}
		unsigned int errors = test<int>(inputFileStreamSeq, inputFileStreamTest);
		std::cout << "Errors: " << errors << '\n';
	}
	std::cout << '\n';
	{ // 5
		std::string fileNameSeq{ "Task_26_05_int.txt" };
		std::string fileNameTest{ "Task_26_05_int_test.txt" };
		std::cout << fileNameSeq << '\n';
		std::ifstream inputFileStreamSeq{ fileNameSeq };
		if (!inputFileStreamSeq)
		{
			throw std::runtime_error("Can't open file " + fileNameSeq);
		}
		std::ifstream inputFileStreamTest{ fileNameTest };
		if (!inputFileStreamTest)
		{
			throw std::runtime_error("Can't open file " + fileNameTest);
		}
		unsigned int errors = test<int>(inputFileStreamSeq, inputFileStreamTest);
		std::cout << "Errors: " << errors << '\n';
	}
}
catch (const std::exception& e)
{
	std::cout << "Exception occured: " << e.what() << '\n';
	return 1;
}
catch (...)
{
	return 2;
}