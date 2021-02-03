#include <iostream>
#include <fstream>
#include "Task_20_Document.h"
#include "Task_26_07_Test_Document.h"

int main()
try
{
	std::string fileNameDocument = { "Task_26_07_Document.txt" };
	std::string fileNameDocumentTests = { "Task_26_07_DocumentTests.txt" };

	std::ifstream inputFileStreamDocument(fileNameDocument);
	std::ifstream inputFileStreamDocumentTests(fileNameDocumentTests);

	if (!inputFileStreamDocument || !inputFileStreamDocumentTests)
	{
		throw std::runtime_error("Can't open file\n");
	}

	Document_Test(inputFileStreamDocument, inputFileStreamDocumentTests);
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