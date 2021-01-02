#ifndef TASK_21_14_STDAFX_H
#include "Task_21_14_stdafx.h"
#endif

int main(int argc, char** argv)
try
{
	unsigned long long int sumString = 0;
	const std::string fileName = "Task_21_14.txt";
	std::map<std::string, int> words = textClean(fileName);
	for (auto i = words.begin(); i != words.end(); ++i)
	{
		std::cout << i->second << '\t' << i->first <<'\n';
	}

	int key;
	while (true)
	{
		std::cout << '\n';
		std::cout <<
			"1 - String was used ...\n" <<
			"2 - The most frequently used word?\n" <<
			"3 - The longest word\n" <<
			"4 - The shortest word\n" <<
			"other number - EXIT\n";
		std::cin >> key;
		std::cout << '\n';
		switch (key)
		{
		case 1:
		{
			std::cout << "Enter string : ";
			std::string temp;
			std::cin >> temp;
			std::cout << "The word '" << temp << "' was repeated " << words[temp] << " times\n";
			break;
		}
		case 2:
		{
			auto temp = words.begin();
			for (auto i = words.begin(); i != words.end(); ++i)
			{
				if (i->second > temp->second)
				{
					temp = i;
				}
			}
			std::cout << "'" << temp->first << "' is the most frequently repeated word (" << temp->second << ")\n";
			break;
		}
		case 3:
		{
			auto temp = words.begin();
			for (auto i = words.begin(); i != words.end(); ++i)
			{
				if (i->first.size() > temp->first.size())
				{
					temp = i;
				}
			}
			std::cout << "The longest word is " << temp->first << '\n';
			break;
		}
		case 4:
		{
			auto temp = words.begin();
			for (auto i = words.begin(); i != words.end(); ++i)
			{
				if (i->first.size() < temp->first.size())
				{
					temp = i;
				}
			}
			std::cout << "The shortest word is " << temp->first << '\n';
			break;
		}
		default:
			return 0;
		}
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