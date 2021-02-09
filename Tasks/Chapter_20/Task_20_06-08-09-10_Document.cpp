#include <iostream>
#include <list>
#include <vector>
#include <fstream>
#include <algorithm>
#include "Task_20_Document.h"

int main()
try
{
	std::string fileName = "Task_20_06-08-09-10.txt";
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
	std::string myString1 = "another";
	Text_iterator findSome = myDoc.find_text(myDoc.begin(), myDoc.end(), myString1);
	if (findSome == myDoc.end())
	{
		std::cout << "string not found\n";
	}
	else
	{
		print(findSome, myDoc.end());
	}
	std::cout << "\n\n";

	std::cout << "Text with replace\n";
	std::string myString2 = "same";
	unsigned long long int count = myDoc.find_text_replace(myDoc.begin(), myDoc.end(), myString1, myString2);
	if (count == 0)
	{
		std::cout << "string not found\n";
	}
	else
	{
		print(myDoc.begin(), myDoc.end());
	}

	std::cout << "\n\n";

	std::cout << "Text with replace\n";
	std::string myString31 = "as12b.\nThe";
	std::string myString32 = "as12b.\nThis";
	count = myDoc.find_text_replace(myDoc.begin(), myDoc.end(), myString31, myString32);
	if (count == 0)
	{
		std::cout << "string not found\n";
	}
	else
	{
		print(myDoc.begin(), myDoc.end());
	}

	std::cout << "\n\n";

	std::cout << "Number of chars in text is " << myDoc.count_chars() << "\n\n";

	std::cout << "Number (1) of words in text is " << myDoc.count_words_1() << "\n\n";

	std::cout << "Number (2) of words in text is " << myDoc.count_words_2() << "\n\n";

	std::string delimiter = " ";
	std::cout << "Number (3) of words in text is " << myDoc.count_words_3(delimiter) << "\n\n";
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