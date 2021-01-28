#ifndef TASK_26_04_STDAFX_H
#include "Task_26_04_stdafx.h"
#endif

int main()
try
{
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
catch (const std::exception& e)
{
	std::cout << "Exception occured: " << e.what() << '\n';
	return 1;
}
catch (...)
{
	return 2;
}