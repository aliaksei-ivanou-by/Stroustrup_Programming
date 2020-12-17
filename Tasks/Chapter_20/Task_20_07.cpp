#ifndef TASK_20_07_STDAFX_H
#include "Task_20_07_stdafx.h"
#endif

int main()
try
{
	std::vector<std::string> myVectorOfString;
	std::string myString;
	std::cout << "Enter words, for exit enter CTRL + Z on a separate line\n";
	while (std::cin >> myString)
	{
		myVectorOfString.push_back(myString);
	}
	auto myVectorOfStringLastWord = findLast(myVectorOfString.begin(), myVectorOfString.end());
	if (myVectorOfStringLastWord != myVectorOfString.end())
	{
		std::cout << *myVectorOfStringLastWord << '\n';
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