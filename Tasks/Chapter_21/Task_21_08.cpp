#ifndef TASK_21_08_STDAFX_H
#include "Task_21_08_stdafx.h"
#endif

int main()
try
{
	const std::string fileName{ "Task_21_08.txt" };
	std::ifstream fileStream{ fileName };
	if (!fileStream)
	{
		throw std::runtime_error("Can't read file");
	}

	std::map<std::string, int> words;
	for (std::string i; fileStream >> i; )
	{
		++words[i];
	}

	std::multimap<int, std::string> frequencies;
	for (const auto& w : words)
	{
		frequencies.insert(std::pair<int, std::string>(w.second, w.first));
	}

	for (auto i = frequencies.begin(); i != frequencies.end(); ++i)
	{
		std::cout << i->first <<": "<< i->second << '\n';
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