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
		throw std::runtime_error("Can't open the file");
	}
	Document myDoc;
	fileStream >> myDoc;
	std::cout << "Original text\n";
	print(myDoc.begin(), myDoc.end());
	std::cout << "\n\n";

	std::cout << "Original text from some word\n";
	std::string myString1 = "Discourse";
	Text_iterator findSome = myDoc.find_text(myString1);
	if (findSome == myDoc.end())
	{
		std::cout << "myString1 not found\n";
	}
	else
	{
		print(findSome, myDoc.end());
	}
	std::cout << "\n\n";

	std::cout << "Text with replace\n";
	std::string myString2 = "Course";
	Text_iterator isReplaced = myDoc.find_replace_text(myString1, myString2);
	if (isReplaced == myDoc.end())
	{
		std::cout << "myString1 not found\n";
	}
	else
	{
		print(myDoc.begin(), myDoc.end());
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