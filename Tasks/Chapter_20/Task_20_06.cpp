#ifndef TASK_20_06_STDAFX_H
#include "Task_20_06_stdafx.h"
#endif

using namespace std;
int main()
try
{
	std::string fileName = "Task_20_06.txt";
	std::ifstream fileStream(fileName.c_str());
	if (!fileStream)
	{
		throw ("Can't open the file");
	}
	Document myDoc;
	fileStream >> myDoc;
	std::cout << "Original text\n";
	print(myDoc, myDoc.begin());
	std::cout << "\n\n";

	std::cout << "Original text from some word\n";
	std::string myString1 = "same";
	Text_iterator findSome = find_text(myDoc.begin(), myDoc.end(), myString1);
	if (findSome == myDoc.end())
	{
		std::cout << "myString1 not found\n";
	}
	else
	{
		print(myDoc, findSome);
	}
	std::cout << "\n\n";

	std::cout << "Text with replace\n";
	std::string myString2 = "specific";
	find_replace_text(myDoc.begin(), myDoc.end(), myString1, myString2);
	print(myDoc, myDoc.begin());
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