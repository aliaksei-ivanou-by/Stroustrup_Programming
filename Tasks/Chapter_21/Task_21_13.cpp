#ifndef TASK_21_13_STDAFX_H
#include "Task_21_13_stdafx.h"
#endif

int main(int argc, char** argv)
try
{
	unsigned long long int sum = 0;
	const std::string fileName = "Task_21_13.txt";
	std::map<std::string, int> words = textClean(fileName);
	for (auto i = words.begin(); i != words.end(); ++i)
	{
		std::cout << i->second << '\t' << i->first <<'\n';
		sum += i->second;
	}
	std::cout << "Total sum of words is: " << sum << '\n';
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