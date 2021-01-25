#ifndef TASK_20_08_STDAFX_H
#include "Task_20_08_stdafx.h"
#endif

using namespace std;
int main()
try
{
	std::string fileName = "Task_20_08.txt";
	std::ifstream fileStream(fileName.c_str());
	if (!fileStream)
	{
		throw std::runtime_error("Can't open the file");
	}
	Document myDoc;
	fileStream >> myDoc;
	std::cout << "Original text\n";
	print(myDoc.begin(), myDoc.end());
	std::cout << "\n\n";

	std::cout << "Number of chars in text is " << myDoc.count_chars();
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