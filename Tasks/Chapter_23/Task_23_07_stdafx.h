#ifndef TASK_23_07_STDAFX_H
#define TASK_23_07_STDAFX_H

#include <iostream>
#include <fstream>
#include <string>
#include <regex>

#endif

bool checkBankCard(const std::sub_match<std::string::const_iterator>& cardMatch)
{
	std::string card = cardMatch.str();
	int len = card.length() - 1;
	int number = 0;
	int sum = 0;
	for (int i = len; i >= 0; i--)
	{
		number = card[i] - '0';
		if (i % 2 == 0)
		{
			number *= 2;
			if (number > 9)
			{
				number -= 9;
			}
		}
		sum += number;
	}
	if (sum % 10 == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool findBankCards(const std::string& line, std::match_results<std::string::const_iterator>& m)
{
	std::regex card{ R"([\d]{13,19})" };
	return std::regex_search(line, m, card);
}