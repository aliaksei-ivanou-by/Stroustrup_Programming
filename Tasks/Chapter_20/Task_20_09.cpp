#ifndef TASK_20_09_STDAFX_H
#include "Task_20_09_stdafx.h"
#endif

using namespace std;
int main()
try
{
	std::string fileName = "Task_20_09.txt";
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

	std::cout << "Number (1) of words in text is " << count_words_1(myDoc);

	std::cout << '\n';

	std::cout << "Number (2) of words in text is " << count_words_2(myDoc);
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