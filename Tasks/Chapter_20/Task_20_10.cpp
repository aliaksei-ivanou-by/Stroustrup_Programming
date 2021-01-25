#ifndef TASK_20_10_STDAFX_H
#include "Task_20_10_stdafx.h"
#endif

using namespace std;
int main()
try
{
	std::string fileName = "Task_20_10.txt";
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

	std::cout << "Number (1) of words in text is " << myDoc.count_words_1();

	std::cout << '\n';

	std::cout << "Number (2) of words in text is " << myDoc.count_words_2();

	std::cout << '\n';

	std::string delimiter = " ";
	std::cout << "Number (3) of words in text is " << myDoc.count_words_3(delimiter);
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