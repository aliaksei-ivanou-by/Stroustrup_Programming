#ifndef TASK_26_05_STDAFX_H
#include "Task_26_05_stdafx.h"
#endif

int main()
try
{
	std::string fileNameSeq{ "Task_26_05_int.txt" };
	std::string fileNameTest{ "Task_26_05_int_test.txt" };
	std::cout << fileNameSeq << '\n';
	std::ifstream inputFileStreamSeq{ fileNameSeq };
	std::ifstream inputFileStreamTest{ fileNameTest };
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